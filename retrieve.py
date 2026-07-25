import json
import warnings
import sys

warnings.filterwarnings("ignore")

# Force UTF-8 for Windows console
if sys.stdout.encoding and sys.stdout.encoding.lower() != "utf-8":
    sys.stdout.reconfigure(encoding="utf-8")

# pyrefly: ignore [missing-import]
from langchain_community.vectorstores import FAISS
# pyrefly: ignore [missing-import]
from langchain_huggingface import HuggingFaceEmbeddings
# pyrefly: ignore [missing-import]
from langchain_community.cross_encoders import HuggingFaceCrossEncoder




# Keep our heavy AI models in memory so they only load once per session
embeddings = None
vectorstore = None
cross_encoder = None
records_dict = None

def init_models():
    global embeddings, vectorstore, cross_encoder, records_dict
    if embeddings is not None:
        return # Already initialized

    print("Loading embeddings...")
    embeddings = HuggingFaceEmbeddings(model_name="BAAI/bge-large-en-v1.5")
    
    print("Loading FAISS vectorstore...")
    vectorstore = FAISS.load_local(
        "faiss_index", embeddings, allow_dangerous_deserialization=True
    )
    
    print("Loading cross-encoder model...")
    try:
        cross_encoder = HuggingFaceCrossEncoder(model_name="BAAI/bge-reranker-large")
    except Exception as e:
        print(f"Warning: Failed to load BAAI/bge-reranker-large, falling back to BAAI/bge-reranker-base. Error: {e}")
        cross_encoder = HuggingFaceCrossEncoder(model_name="BAAI/bge-reranker-base")
    
    print("Loading records from analyzed_problems.json...")
    with open("analyzed_problems.json", "r", encoding="utf-8") as f:
        _records = json.load(f)
        records_dict = {
            r["title_slug"]: r for r in _records if "title_slug" in r
        }


def retrieve_similar_problems(
    query_text: str,
    top_k_retrieve: int = 15,
    top_k_final: int = 5,
    dense_weight: float = 0.6,
) -> tuple[list[dict], bool]:
    """
    Retrieve semantically similar problems using FAISS dense similarity blended with cross-encoder reranking.
    Returns (results, is_confident).
    """
    if vectorstore is None or cross_encoder is None or records_dict is None:
        init_models()

    # Get dense results WITH distance scores
    base_docs_with_dist = vectorstore.similarity_search_with_score(query_text, k=top_k_retrieve)
    base_docs = [doc for doc, _ in base_docs_with_dist]
    dense_distances = [dist for _, dist in base_docs_with_dist]

    # Normalize FAISS distance (lower = better) into similarity (higher = better), 0 to 1
    max_dist = max(dense_distances) if dense_distances else 1.0
    min_dist = min(dense_distances) if dense_distances else 0.0
    dist_range = max(max_dist - min_dist, 1e-6)
    dense_scores_norm = [1 - ((d - min_dist) / dist_range) for d in dense_distances]

    # Cross-encoder scores, normalized the same way (min-max within this batch)
    pairs = [[query_text, doc.page_content] for doc in base_docs]
    ce_scores = cross_encoder.score(pairs)
    max_ce, min_ce = max(ce_scores), min(ce_scores)
    ce_range = max(max_ce - min_ce, 1e-6)
    ce_scores_norm = [(s - min_ce) / ce_range for s in ce_scores]

    # Blend: weighted combination instead of pure cross-encoder ranking
    blended = [
        dense_weight * d + (1 - dense_weight) * c
        for d, c in zip(dense_scores_norm, ce_scores_norm)
    ]

    docs_with_scores = list(zip(base_docs, blended))
    docs_with_scores.sort(key=lambda x: x[1], reverse=True)

    results = []
    for doc, score in docs_with_scores[:top_k_final]:
        title_slug = doc.metadata.get("title_slug")
        if title_slug and title_slug in records_dict:
            full_record = dict(records_dict[title_slug])
            full_record["similarity_score"] = round(float(score), 4)
            results.append(full_record)

    # Blended score is now genuinely bounded 0-1 by construction (min-max normalized),
    # unlike the old raw unbounded cross-encoder logit — threshold is meaningful now.
    is_confident = bool(results) and results[0]["similarity_score"] > 0.55

    return results, is_confident


if __name__ == "__main__":
    if len(sys.argv) > 1:
        test_queries = [" ".join(sys.argv[1:])]
    else:
            test_queries = [
        "Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.",
        "Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator",
        "Given a 2D grid of 1s (land) and 0s (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.",
        "Given an array of integers, return indices of the two numbers such that they add up to a specific target.",
        "Given a string, find the length of the longest palindromic substring.",
        "You are given an array of intervals where intervals[i] = [starti, endi]. Merge all overlapping intervals.",
        "find shortest path in a weighted graph",
        "detect a cycle in a linked list",
        "Given the root of a binary tree, return its maximum depth.",
        "Find the length of the longest substring without repeating characters without using extra space.",
        "Given a sorted array of distinct integers, return the smallest index where a target could be inserted to keep it sorted.",
        "check if a string of parentheses brackets and braces is valid",
        "find the kth largest element in an unsorted array",
        "merge two sorted linked lists into one sorted list","Given an integer array nums and two integers lower and upper, return the number of range sums that lie in [lower, upper] inclusive.Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j inclusive, where i <= j"
    ]
    print("Running default test queries...")
    init_models()

    for q_idx, test_query in enumerate(test_queries, 1):
        print(f"\n--- Query {q_idx}: '{test_query}' ---")
        
        results, is_confident = retrieve_similar_problems(test_query, top_k_retrieve=15, top_k_final=5)
        
        if not is_confident:
            print("GATED - no confident match. Closest matches are:")
            for i, r in enumerate(results[:3], 1):
                print(f"{i}. [Score: {r['similarity_score']:.4f}] {r['title_slug']} -> {r.get('pattern_family', 'UNKNOWN')}")
        else:
            print("Confident Results:")
            for i, r in enumerate(results, 1):
                print(f"{i}. [Score: {r['similarity_score']:.4f}] {r['title_slug']} -> {r.get('pattern_family', 'UNKNOWN')}")
