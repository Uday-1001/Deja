import os
import re
import json
import time
import sys
import argparse
from datetime import datetime, timezone
from pathlib import Path
# pyrefly: ignore [missing-import]
from dotenv import load_dotenv
# pyrefly: ignore [missing-import]
from openai import OpenAI, RateLimitError, APIError

load_dotenv()

# Forces UTF-8 output encoding.
# Keeps our emojis looking pretty on Windows consoles.
if sys.stdout.encoding.lower() != 'utf-8':
    sys.stdout.reconfigure(encoding='utf-8')

# Boots up the API client for Groq.
# We use this to analyze problems blazing fast.
GROQ_API_KEY = os.getenv("GROQ_API_KEY")
if not GROQ_API_KEY:
    print("Error: GROQ_API_KEY not found in .env")
    exit(1)

client = OpenAI(
    api_key=GROQ_API_KEY,
    base_url="https://api.groq.com/openai/v1",
)

MODEL = "llama-3.3-70b-versatile"
# Basic delay to avoid getting banned.
# Groq is fast, but their rate limits can still bite.
BASE_DELAY_SEC = 2.5
# Caps the amount of code we send.
# Saves tokens and keeps the AI focused on the core logic.
MAX_CODE_CHARS = 4000

SYSTEM_PROMPT = (
    "You are an expert competitive programmer and algorithm analyst. "
    "Your task is to analyze programming problems and accepted solutions to identify "
    "the primary algorithmic technique actually used by the implementation. "
    "Always return valid JSON matching the requested schema exactly."
)

PATTERN_FAMILIES = (
    "Sliding Window, Two Pointer, Dynamic Programming, Bitmask DP, Digit DP, "
    "Greedy, Binary Search, Binary Search on Answer, Graph-BFS, Graph-DFS, "
    "Dijkstra, Bellman-Ford, Floyd-Warshall, Topological Sort, Minimum Spanning Tree, "
    "Union-Find, Tree, Binary Tree, Binary Search Tree, Trie, Segment Tree, "
    "Fenwick Tree, Sparse Table, Heap-PriorityQueue, Monotonic Stack, Monotonic Queue, "
    "Prefix Sum, Difference Array, Hash Map-Set, Sorting, Divide and Conquer, "
    "Meet in the Middle, Backtracking, Bit Manipulation, Math-Number Theory, "
    "Matrix Exponentiation, String Matching, KMP, Rolling Hash, Simulation, "
    "Linked List, Recursion, Geometry, Interactive, Other"
)

PROMPT_TEMPLATE = """You are analyzing a competitive programming solution to extract its underlying algorithmic pattern, for a personal knowledge base that will later match new problems to similar past ones.

INPUT:
Problem Title: {title}
Problem Statement: {problem_statement}
Accepted Solution Code:
{my_solution_code}

TASK:
Analyze the problem statement and the accepted solution together. Identify the core algorithmic technique actually used in the code, the key insight that makes this technique applicable, the complexity, the programming language of the code, the estimated difficulty, and the relevant topic tags.

Return ONLY valid JSON with exactly these fields, and nothing else — no markdown code fences, no explanation before or after:

{{
  "lang": "The programming language of the solution code (e.g., 'python', 'cpp', 'java', 'javascript', etc.)",
  "difficulty": "Estimated difficulty of the problem ('Easy', 'Medium', or 'Hard')",
  "topics_tagged": ["List", "of", "relevant", "topic", "tags", "e.g.", "Array", "Dynamic Programming"],
  "core_technique": "One specific sentence naming the exact technique/data structure/algorithm used in this code (e.g. 'Two-pointer with fixed window shrink' not just 'Array')",
  "key_insight": "One to two sentences on the non-obvious realization or observation that makes this technique work for this specific problem",
  "time_complexity": "Big-O notation, e.g. O(n log n)",
  "space_complexity": "Big-O notation, e.g. O(1)",
  "pattern_family": "Your best single-label guess from this list: {pattern_families}. This is an advisory label, not strictly enforced — prioritize accuracy in core_technique over forcing a fit here.",
  "trigger_signals": "What specific phrases, constraints, or structural cues in a NEW problem's statement would hint that this same technique applies. Be concrete and specific (e.g. 'asks for maximum/minimum subarray sum with a fixed or variable size constraint' rather than 'array problem')",
  "embedding_text": "Write a dense 2-3 sentence paragraph in natural language — do NOT simply concatenate the other fields. Naturally describe: (1) the algorithm family and primary technique, (2) the key observation that makes it work, (3) the conditions or problem structure that should trigger recognition of this pattern, and (4) any common constraints or phrasing (e.g. 'k-length window', 'find the shortest path', 'at most X operations') that signal this approach. Optimize for semantic search: a new problem description should retrieve this record when it shares the same underlying structure."
}}

Rules:
- Base your analysis on what the CODE actually does, not just what the topic tags suggest — sometimes the tags are broader than the actual technique used.
- Be specific and technical, not generic. Avoid vague phrases like "uses an algorithm to solve the problem."
- If the code uses a combination of techniques, name the primary/defining one in core_technique but you may mention the secondary one briefly in key_insight.
- pattern_family MUST be copied EXACTLY, character-for-character, from the provided list — do not invent, rename, abbreviate, or generalize a category (e.g. do not output "Brute Force," "Exhaustive Search," or "Simple Iteration" even if they seem more descriptive). If the solution is a direct brute-force enumeration, simple simulation, or does not clearly match any named pattern in the list, use "Other".
- Do not include any text outside the JSON object.
"""

REQUIRED_FIELDS = {
    "lang",
    "difficulty",
    "core_technique",
    "key_insight",
    "time_complexity",
    "space_complexity",
    "pattern_family",
    "trigger_signals",
    "embedding_text",
}

# A locked-down list of allowed categories.
# Prevents the AI from hallucinating weird new algorithms!
ALLOWED_PATTERN_FAMILIES: set[str] = {
    v.strip() for v in PATTERN_FAMILIES.split(",") if v.strip()
}

# Sniffs out standard Big-O notation.
# Ensures the AI actually tells us the time/space complexity properly.
_COMPLEXITY_RE = re.compile(
    r"O\s*\(.*\)",
    re.IGNORECASE,
)

# Catches lazy AI responses like "N/A" or "Unknown".
# We block these so they don't pollute our database.
_PLACEHOLDER_PATTERNS = re.compile(
    r"^(?:n/?a|unknown|none|not\s+applicable|generic|tbd|-)$",
    re.IGNORECASE,
)

# Sets a word count floor for specific fields.
# Forces the AI to actually explain things instead of one-word answers.
_MIN_WORDS: dict[str, int] = {
    "core_technique": 2,
    "key_insight": 10,
    "trigger_signals": 10,
    "embedding_text": 25,
}


def _word_count(s: str) -> int:
    return len(s.split())


def validate_analysis(data: dict):
    # Thoroughly audits the AI's JSON output.
    # Checks required fields, Big-O formats, and word counts so we don't save garbage.
    # Validate that every required field actually exists and isn't empty
    for field in REQUIRED_FIELDS:
        val = data.get(field)
        if val is None:
            return False, f"missing field: '{field}'"
        if not isinstance(val, str):
            return False, f"field '{field}' is not a string (got {type(val).__name__})"
        if not val.strip():
            return False, f"field '{field}' is empty"

    # Reject any fields where the LLM gave a lazy placeholder response
    for field in REQUIRED_FIELDS:
        val = data[field].strip()
        if _PLACEHOLDER_PATTERNS.match(val):
            return False, f"field '{field}' contains a placeholder value: '{val}'"

    # Validate topics_tagged
    topics = data.get("topics_tagged")
    if not isinstance(topics, list) or not all(isinstance(t, str) for t in topics) or len(topics) == 0:
        return False, "field 'topics_tagged' must be a non-empty list of strings"

    # Validate difficulty
    diff = data.get("difficulty", "").strip().lower()
    if diff not in ["easy", "medium", "hard"]:
        return False, f"field 'difficulty' must be Easy, Medium, or Hard (got '{data.get('difficulty')}')"

    # Ensure the pattern family strictly matches our defined taxonomy
    pf = data["pattern_family"].strip()
    if pf not in ALLOWED_PATTERN_FAMILIES:
        print(f"\n    Note: pattern_family '{pf}' is outside the standard taxonomy — accepting anyway since core_technique is the primary signal now.")

    # Verify that time and space complexities are valid Big-O expressions
    for field in ("time_complexity", "space_complexity"):
        val = data[field].strip()
        if not _COMPLEXITY_RE.search(val):
            return False, (
                f"{field} '{val}' does not look like Big-O notation "
                f"(expected e.g. O(n log n), O(1), O(V+E))"
            )

    # Check that the textual explanations meet our length requirements for quality
    for field, min_words in _MIN_WORDS.items():
        wc = _word_count(data[field])
        if wc < min_words:
            return False, (
                f"field '{field}' is too short: {wc} word(s), "
                f"minimum is {min_words}"
            )

    return True, None

def analyze_problem(problem):
    # Scrubs the input data.
    # Prevents string formatting from crashing if fields are None.
    title = problem.get("title") or ""
    problem_statement = problem.get("problem_statement") or ""
    my_solution_code = (problem.get("my_solution_code") or "")[:MAX_CODE_CHARS]

    prompt = PROMPT_TEMPLATE.format(
        title=title,
        problem_statement=problem_statement,
        my_solution_code=my_solution_code,
        pattern_families=PATTERN_FAMILIES,
    )

    try:
        response = client.chat.completions.create(
            model=MODEL,
            messages=[
                {"role": "system", "content": SYSTEM_PROMPT},
                {"role": "user", "content": prompt},
            ],
            response_format={"type": "json_object"},
            temperature=0.2,  # Low temperature for deterministic/analytical responses
            max_tokens=1500,   # Increased for larger models that output more text
        )

        content = response.choices[0].message.content
        try:
            data = json.loads(content)
        except json.JSONDecodeError as exc:
            return {"error": "invalid_json", "message": f"json.loads failed: {exc}", "raw": content[:300]}

        is_valid, reason = validate_analysis(data)
        if not is_valid:
            return {"error": "incomplete_json", "message": reason, "raw": content[:300]}

        return data
        
    except RateLimitError as e:
        # Checks how long we need to wait after a rate limit.
        # We cap this to 60s so the script doesn't hang forever.
        MAX_WAIT = 60.0  # Never wait more than 60s — Groq can return 1000+ second values
        retry_after = e.response.headers.get("Retry-After") if hasattr(e, 'response') and e.response is not None else None
        if retry_after:
            try:
                raw_delay = float(retry_after)
                delay = min(raw_delay + 1.0, MAX_WAIT)
                print(f"    [RateLimit] Groq returned 429. Retry-After={raw_delay}s → capped to {delay:.0f}s.")
                print(f"    [RateLimit Details]: {e.message if hasattr(e, 'message') else str(e)}")
                return {"error": "rate_limit", "retry_after": delay}
            except ValueError:
                pass
        
        # Uses a default timeout if the API doesn't specify.
        # Standard safety net for unknown 429s.
        print(f"    [RateLimit] Groq returned 429. No valid Retry-After header. e: {e}")
        return {"error": "rate_limit", "retry_after": 60.0}
        
    except APIError as e:
        print(f"    [APIError] {e}")
        return {"error": "api_error", "message": str(e)}
        
    except Exception as e:
        print(f"    [Error] {e}")
        return {"error": "unknown_error", "message": str(e)}

def main():
    parser = argparse.ArgumentParser(description="Analyze LeetCode problems to extract algorithmic patterns.")
    parser.add_argument("--input", default="problems.json", help="Input JSON file from ingest.py")
    parser.add_argument("--output", default="analyzed_problems.json", help="Output JSON file for analyzed problems")
    parser.add_argument("--limit", type=int, default=None, help="Process at most N problems (useful for testing)")
    args = parser.parse_args()

    in_path = Path(args.input)
    if not in_path.exists():
        print(f"Input file not found: {in_path}")
        exit(1)

    with open(in_path, "r", encoding="utf-8") as f:
        problems = json.load(f)

    # Scans for previously analyzed problems.
    # Lets us safely resume where we left off without repeating work!
    out_path = Path(args.output)
    analyzed_data = {}
    if out_path.exists():
        try:
            with open(out_path, "r", encoding="utf-8") as f:
                analyzed_list = json.load(f)
                analyzed_data = {p["title_slug"]: p for p in analyzed_list}
            print(f"Resuming: found {len(analyzed_data)} already-analyzed problems in {out_path}")
        except json.JSONDecodeError:
            pass

    processed_this_run = 0
    run_start = time.time()

    # Calculates the remaining workload.
    # Super helpful for estimating how long the batch job will take.
    pending = [
        (i, p) for i, p in enumerate(problems)
        if p["title_slug"] not in analyzed_data or "core_technique" not in analyzed_data[p["title_slug"]]
    ]
    if args.limit:
        pending = pending[:args.limit]

    total_pending = len(pending)
    print(f"Problems to analyze: {total_pending}  (skipping {len(problems) - total_pending} already done)")

    for job_idx, (orig_idx, problem) in enumerate(pending):
        slug = problem["title_slug"]

        print(f"[{job_idx + 1}/{total_pending}] {slug}", end="", flush=True)

        start_time = time.time()

        # Retries the request a few times if the AI fumbles.
        # We give it multiple chances to output valid JSON.
        rate_limit_retries = 10
        validation_retries = 2
        success = False

        while rate_limit_retries > 0 and validation_retries > 0 and not success:
            result = analyze_problem(problem)

            if "error" in result:
                err = result["error"]
                if err == "rate_limit":
                    delay = result.get("retry_after", 60.0)
                    print(f"\n    [RateLimit] waiting {delay:.0f}s... ({rate_limit_retries - 1} RL retries left)", flush=True)
                    time.sleep(delay)
                    rate_limit_retries -= 1
                elif err in ("invalid_json", "incomplete_json"):
                    print(f"\n    [{err}] {result.get('message')} - retrying ({validation_retries - 1} val retries left)", flush=True)
                    validation_retries -= 1
                    if validation_retries > 0:
                        time.sleep(2.0)  # brief pause before retry
                else:
                    print(f"\n    [FAIL] {err}: {result.get('message')} - skipping", flush=True)
                    break  # non-retriable errors (APIError, etc.)
            else:
                elapsed_req = time.time() - start_time
                # Stamps the metadata on successful results.
                # Helps us track which model analyzed what, and when.
                result["analysis_model"] = MODEL
                result["analysis_version"] = 1
                result["analysis_timestamp"] = datetime.now(timezone.utc).isoformat()

                merged = problem.copy()
                merged.update(result)
                analyzed_data[slug] = merged
                success = True

                # Estimates the remaining time for the whole batch.
                # Updates the progress bar with a live ETA.
                processed_this_run += 1
                elapsed_total = time.time() - run_start
                avg_per_problem = elapsed_total / processed_this_run
                remaining = total_pending - (job_idx + 1)
                eta_sec = avg_per_problem * remaining
                eta_str = f"{int(eta_sec // 60)}m{int(eta_sec % 60):02d}s" if eta_sec >= 60 else f"{eta_sec:.0f}s"

                print(
                    f" OK [{elapsed_req:.2f}s req | {processed_this_run} done | ~{eta_str} left]",
                    flush=True,
                )

                # Checkpoints our progress every 5 problems.
                # A lifesaver if the script crashes halfway through!
                if processed_this_run % 5 == 0:
                    with open(out_path, "w", encoding="utf-8") as f:
                        json.dump(list(analyzed_data.values()), f, ensure_ascii=False, indent=2)
                    print(f"  ...checkpoint: {len(analyzed_data)} total problems saved")

        if not success:
            # Gives up after burning all our retries.
            # We skip the problem rather than crashing the whole loop.
            print(f" FAIL skipped after exhausting retries", flush=True)

        # Enforces our base rate-limit delay.
        # Keeps Groq happy so they don't block our IP.
        elapsed = time.time() - start_time
        sleep_time = max(0, BASE_DELAY_SEC - elapsed)
        if sleep_time > 0:
            time.sleep(sleep_time)

    # Flushes all final data to disk.
    # The batch job is officially done!
    with open(out_path, "w", encoding="utf-8") as f:
        json.dump(list(analyzed_data.values()), f, ensure_ascii=False, indent=2)

    total_elapsed = time.time() - run_start
    print(f"\nDone in {total_elapsed:.1f}s. Processed {processed_this_run} new problems this run.")
    print(f"Total analyzed problems: {len(analyzed_data)}")

if __name__ == "__main__":
    main()
