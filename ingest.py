import os
import json
import time
import subprocess
from analyze import analyze_problem
from build_vectorstore import build_page_content


def run_ingestion(problem_statement: str, title_slug: str = None, code: str = None):
    print("\n================== INGESTION ==================")
    if code is None:
        if not os.path.exists("solution.py"):
            print("Error: 'solution.py' does not exist.")
            print("Please save your solution in 'solution.py' and try again.")
            return

        with open("solution.py", "r", encoding="utf-8") as f:
            code = f.read().strip()
            
        if not code:
            print("Error: 'solution.py' is empty.")
            print("Please save your solution in 'solution.py' and try again.")
            return

    if title_slug is None:
        title_slug = input("Enter a title-slug for this problem (e.g., 'two-sum'): ").strip()
        
    if not title_slug:
        print("Title slug cannot be empty. Ingestion aborted.")
        return
        
        
    print(f"\n[System] Analyzing solution for '{title_slug}' via Groq...")
    
    problem = {
        "title": title_slug,
        "title_slug": title_slug,
        "problem_statement": problem_statement,
        "my_solution_code": code
    }
    
    # Retries the API call if we hit rate limits.
    # Ensures we don't crash just because the server is busy.
    max_retries = 3
    for attempt in range(max_retries):
        analysis = analyze_problem(problem)
        if "error" in analysis:
            if analysis["error"] == "rate_limit":
                delay = analysis.get("retry_after", 60.0)
                print(f"[RateLimit] Waiting {delay:.0f}s before retrying...")
                time.sleep(delay)
                continue
            else:
                print(f"[Analysis Error] {analysis['message']}")
                return
        
        # Merges the fresh AI analysis with the base problem.
        # This builds out a complete, searchable record.
        problem.update(analysis)
        problem["analysis_model"] = "llama-3.3-70b-versatile"
        
        # Saves the solved problem to our local JSON database.
        # This keeps a persistent record of everything you've learned.
        print("[System] Analysis complete. Saving to analyzed_problems.json...")
        records = []
        if os.path.exists("analyzed_problems.json"):
            with open("analyzed_problems.json", "r", encoding="utf-8") as f:
                records = json.load(f)
                
        # Removes old versions of this problem.
        # This prevents duplicates and ensures we only keep your latest solution.
        records = [r for r in records if r.get("title_slug") != title_slug]
        records.append(problem)
        
        with open("analyzed_problems.json", "w", encoding="utf-8") as f:
            json.dump(records, f, indent=2, ensure_ascii=False)
            
        print("[System] Updating FAISS vectorstore incrementally...")
        try:
            # pyrefly: ignore [missing-import]
            from langchain_core.documents import Document
            # pyrefly: ignore [missing-import]
            from langchain_huggingface import HuggingFaceEmbeddings
            # pyrefly: ignore [missing-import]
            from langchain_community.vectorstores import FAISS

            embeddings = HuggingFaceEmbeddings(model_name="BAAI/bge-large-en-v1.5")
            
            page_content = build_page_content(problem)
            metadata = {
                k: v for k, v in problem.items() 
                if k not in ["embedding_text", "my_solution_code"]
            }
            doc = Document(page_content=page_content, metadata=metadata)
            
            if os.path.exists("faiss_index"):
                vectorstore = FAISS.load_local("faiss_index", embeddings, allow_dangerous_deserialization=True)
                vectorstore.add_documents([doc])
                vectorstore.save_local("faiss_index")
                print("\n[System] Incremental update successful! Your solution is now searchable.")
            else:
                import sys
                import subprocess
                subprocess.run([sys.executable, "build_vectorstore.py"], check=True)
                print("\nIngestion successful! Your solution is now searchable.")
                
            return {"status": "success", "message": "Ingestion successful!"}
        except Exception as e:
            print(f"\nError updating vectorstore: {e}")
            return {"status": "error", "message": str(e)}
        
    print("Ingestion failed after maximum retries.")
    return {"status": "error", "message": "Failed after max retries."}

if __name__ == "__main__":
    # Simple test harness for local debugging.
    # Runs a dummy problem through the ingestion pipeline.
    run_ingestion("This is a test problem statement.")