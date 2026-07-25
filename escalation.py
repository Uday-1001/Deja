import sys
from retrieve import retrieve_similar_problems
from hint_generator import generate_hint
from ingest import run_ingestion

def get_multiline_input(prompt_text: str) -> str:
    print(prompt_text)
    print("(Enter an empty line or press Ctrl-D to finish)")
    lines = []
    while True:
        try:
            line = input()
        except EOFError:
            break
        if line.strip() == "":
            break
        lines.append(line)
    return "\n".join(lines).strip()

def main():
    print("=======================================")
    print(" Deja Problem Solver - Escalation Flow ")
    print("=======================================")
    
    problem_statement = get_multiline_input("\nPlease paste the problem statement:")
    
    if not problem_statement:
        print("No problem statement provided. Exiting.")
        sys.exit(0)
        
    print("\n[System] Retrieving similar past problems...")
    results = retrieve_similar_problems(problem_statement, top_k_retrieve=15, top_k_final=5)
    
    if not results:
        print("\n--- NO CONFIDENT MATCH ---")
        print(generate_hint(problem_statement, results, stage="hint"))
        sys.exit(0)
        
    # Stage 1: Give the user a gentle nudge towards the right algorithmic pattern
    print("\n================== STAGE 1: HINT ==================")
    print(generate_hint(problem_statement, results, stage="hint"))
    print("===================================================\n")
    
    while True:
        resp = input("Did this hint help you solve it? (y/n/p for pseudocode): ").strip().lower()
        if resp in ['y', 'yes']:
            ans = input("\nAwesome! Would you like to ingest your new solution from 'solution.py' into the database? (y/n): ").strip().lower()
            if ans in ['y', 'yes']:
                run_ingestion(problem_statement)
            sys.exit(0)
        elif resp in ['n', 'no', 'p']:
            break
        else:
            print("Please answer 'y', 'n', or 'p'.")

    # Stage 2: Break down the logic step-by-step without giving away the exact code
    print("\n=============== STAGE 2: PSEUDOCODE ===============")
    print(generate_hint(problem_statement, results, stage="pseudocode"))
    print("===================================================\n")
    
    while True:
        resp = input("Did this pseudocode help you solve it? (y/n/c for full code): ").strip().lower()
        if resp in ['y', 'yes']:
            ans = input("\nAwesome! Would you like to ingest your new solution from 'solution.py' into the database? (y/n): ").strip().lower()
            if ans in ['y', 'yes']:
                run_ingestion(problem_statement)
            sys.exit(0)
        elif resp in ['n', 'no', 'c']:
            break
        else:
            print("Please answer 'y', 'n', or 'c'.")
            
    # Stage 3: Reveal the optimal reference implementation for study
    print("\n================== STAGE 3: CODE ==================")
    print(generate_hint(problem_statement, results, stage="code"))
    print("===================================================\n")
    
    while True:
        resp = input("Did this reference solution help you solve it? (y/n): ").strip().lower()
        if resp in ['y', 'yes']:
            ans = input("\nGreat! Would you like to ingest your new adaptation from 'solution.py' into the database? (y/n): ").strip().lower()
            if ans in ['y', 'yes']:
                run_ingestion(problem_statement)
            sys.exit(0)
        elif resp in ['n', 'no']:
            print("\nThis might be a tough one! Try breaking it down from first principles or reviewing related topics.")
            sys.exit(0)
        else:
            print("Please answer 'y' or 'n'.")

if __name__ == "__main__":
    main()
