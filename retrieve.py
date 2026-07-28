import json
import warnings
import sys
import math

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


# Caches the heavy AI models in memory.
# This prevents painful reload times on every single query!
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
    top_k_retrieve: int = 40,
    top_k_final: int = 5,
    dense_weight: float = 0.10,
) -> tuple[list[dict], bool]:
    # Searches the database for similar problems using dense vectors and a cross-encoder.
    # Returns the best matches and a boolean flag indicating if we're highly confident.
    if vectorstore is None or cross_encoder is None or records_dict is None:
        init_models()

    # Grabs the initial wide net of results from FAISS.
    # We pull extra results here since we'll rerank them later.
    base_docs_with_dist = vectorstore.similarity_search_with_score(query_text, k=top_k_retrieve)
    base_docs = [doc for doc, _ in base_docs_with_dist]
    dense_distances = [dist for _, dist in base_docs_with_dist]

    # Converts FAISS L2 distance into a standard 0-to-1 similarity score.
    # Makes the math much easier to work with.
    dense_scores_norm = [max(0.0, 1.0 - (d**2) / 2.0) for d in dense_distances]

    # Runs the results through our cross-encoder for deep semantic checking.
    # We convert its raw output into a clean 0-to-1 probability score.
    pairs = [[query_text, doc.page_content] for doc in base_docs]
    ce_scores = cross_encoder.score(pairs)
    ce_scores_norm = [1.0 / (1.0 + math.exp(-s)) for s in ce_scores]

    # Blends both scores together to create the ultimate ranking.
    # We heavily favor the cross-encoder since it's much smarter.
    blended = [
        dense_weight * d + (1 - dense_weight) * c
        for d, c in zip(dense_scores_norm, ce_scores_norm)
    ]

    docs_with_scores = list(zip(base_docs, blended, ce_scores_norm, dense_scores_norm))
    docs_with_scores.sort(key=lambda x: x[1], reverse=True)

    results = []
    top_ce_sigmoid = 0.0
    top_dense_score = 0.0
    for rank, (doc, score, ce_sig, d_sig) in enumerate(docs_with_scores[:top_k_final]):
        title_slug = doc.metadata.get("title_slug")
        if title_slug and title_slug in records_dict:
            full_record = dict(records_dict[title_slug])
            full_record["similarity_score"] = round(float(score), 4)
            full_record["ce_sigmoid"]        = round(float(ce_sig), 4)
            full_record["dense_score"]       = round(float(d_sig), 4)
            results.append(full_record)
            if rank == 0:
                # Casts scores to native Python floats.
                # Prevents annoying JSON serialization crashes later on.
                top_ce_sigmoid = float(ce_sig)
                top_dense_score = float(d_sig)

    # The ultimate confidence check! We make sure the models actually agree it's a good match.
    # If the scores are too low, we admit we aren't confident instead of guessing blindly.
    is_confident = bool(
        results and (
            top_ce_sigmoid > 0.62
            or (top_dense_score > 0.82 and top_ce_sigmoid > 0.51)
        )
    )

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
