import json
import random
import os
import sys

# Ensure the project root is on sys.path regardless of cwd
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from retrieve import retrieve_similar_problems, init_models

# Abstract algorithm queries to simulate unseen problems. 
# Maps natural language to the expected algorithmic pattern families.
PATTERN_QUERIES = [
    ("Given a massive text document and a list of fixed-size keywords, find all starting positions where every keyword appears exactly once consecutively.", {"Sliding Window", "Hash Map-Set"}),
    ("Determine if one sequence of characters can be formed by repeatedly splitting another sequence into binary trees and swapping their children at various nodes.", {"Dynamic Programming"}),
    ("Count the exact number of ways you can delete characters from a long sequence to perfectly form a specific target sequence.", {"Dynamic Programming"}),
    ("Create a perfect deep copy of a complex network structure where every node has a list of neighbors, ensuring no memory references to the original network remain.", {"Graph-DFS", "Graph-BFS"}),
    ("Given a 2D grid of random letters and a massive dictionary of words, efficiently find all the dictionary words hidden in the grid by tracing paths of adjacent letters.", {"Trie", "Backtracking", "Graph-DFS"}),
    ("You have a sequence of objects each with a point value. Removing one gives you points based on its neighbors. Find the order of removal that maximizes total points.", {"Dynamic Programming", "Divide and Conquer"}),
    ("Given two massive numbers represented entirely as text strings, write an algorithm to calculate their exact mathematical product without using built-in big integer libraries.", {"Math", "String", "Simulation"}),
    ("Determine if a given text string represents a mathematically valid numerical value, taking into account decimals, scientific e-notation, and positive/negative signs.", {"String", "Simulation"}),
    ("Find the nth number in a sequence where every valid number must only have prime factors of 2, 3, or 5. You must generate them in ascending order.", {"Math", "Dynamic Programming", "Heap-PriorityQueue"}),
    ("In a secret number guessing game, figure out how many digits are perfectly placed (bulls) and how many are the right number but in the wrong spot (cows).", {"Hash Map-Set", "Counting"}),
]

def evaluate_exact_accuracy(records, sample_size=20):
    """Runs an exact-duplicate retrieval test on a random sample of past problems."""
    eligible = [r for r in records if r.get("problem_statement", "").strip()]
    sample = random.Random(0).sample(eligible, min(sample_size, len(eligible)))
    
    hits = 0
    mrr_sum = 0.0

    print(f"Testing {len(sample)} problems for exact-duplicate retrieval...")
    
    for i, record in enumerate(sample):
        results, _ = retrieve_similar_problems(record["problem_statement"], top_k_retrieve=15, top_k_final=5)
        rank = next((idx + 1 for idx, r in enumerate(results) if r["title_slug"] == record["title_slug"]), 0)
        
        if rank == 1: hits += 1
        if rank > 0: mrr_sum += 1.0 / rank

    return hits / len(sample), mrr_sum / len(sample)


def evaluate_unseen_accuracy():
    """Tests if abstract queries return problems matching the correct algorithmic pattern."""
    hits = 0
    mrr_sum = 0.0

    print(f"\nTesting {len(PATTERN_QUERIES)} abstract queries for conceptual retrieval...")
    
    for query, expected_patterns in PATTERN_QUERIES:
        results, _ = retrieve_similar_problems(query, top_k_retrieve=15, top_k_final=5)
        
        # Find the rank of the first result that matches the expected algorithmic pattern
        rank = next((idx + 1 for idx, r in enumerate(results) if r.get("pattern_family") in expected_patterns), 0)
        
        if rank == 1: hits += 1
        if rank > 0: mrr_sum += 1.0 / rank

    return hits / len(PATTERN_QUERIES), mrr_sum / len(PATTERN_QUERIES)


def main():
    print("Loading models (this takes a few seconds)...")
    init_models()

    with open("analyzed_problems.json", "r", encoding="utf-8") as f:
        records = json.load(f)

    exact_acc, exact_mrr = evaluate_exact_accuracy(records)
    unseen_acc, unseen_mrr = evaluate_unseen_accuracy()
    
    print(f"\n{'='*45}")
    print("EVALUATION RESULTS")
    print(f"{'='*45}")
    print(f"Exact-Duplicate  | Accuracy: {exact_acc:.1%}  MRR: {exact_mrr:.3f}")
    print(f"Unseen Problems  | Accuracy: {unseen_acc:.1%}  MRR: {unseen_mrr:.3f}")
    print(f"{'='*45}")


if __name__ == "__main__":
    main()
