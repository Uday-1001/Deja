import json
import os
# pyrefly: ignore [missing-import]
from langchain_core.documents import Document
# pyrefly: ignore [missing-import]
from langchain_huggingface import HuggingFaceEmbeddings
# pyrefly: ignore [missing-import]
from langchain_community.vectorstores import FAISS

# Builds the content string for our vector database.
# This ensures all records have a unified, rich structure for accurate searching.
def build_page_content(record: dict) -> str:
    return (
        f"{record.get('problem_statement', '')}\n\n"
        f"Pattern: {record.get('pattern_family', '')}\n"
        f"Technique: {record.get('core_technique', '')}\n"
        f"Trigger signals: {record.get('trigger_signals', '')}\n"
        f"{record.get('embedding_text', '')}"
    )


def build_vectorstore():
    # Loads the structured problem data from disk.
    # This JSON file contains all the LLM analysis we've done so far.
    with open("analyzed_problems.json", "r", encoding="utf-8") as f:
        records = json.load(f)

    # Wakes up the embedding model.
    # It translates our text into dense vectors so we can do similarity math on them.
    print("Loading embedding model...")
    embeddings = HuggingFaceEmbeddings(model_name="BAAI/bge-large-en-v1.5")

    # Preps each problem record into a standard Document object.
    # These documents are what FAISS will actually index and search.
    documents = []
    skipped = 0
    warned = 0
    print(f"Creating documents for {len(records)} records...")
    for record in records:
        has_stmt = bool(record.get("problem_statement", "").strip())
        has_emb  = bool(record.get("embedding_text", "").strip())

        if not has_stmt and not has_emb:
            # Skips totally empty records.
            # We can't index a problem if we have literally zero text for it.
            skipped += 1
            continue

        if not has_stmt or not has_emb:
            # Logs a heads-up for incomplete records.
            # We still index them using whatever text fields they DO have.
            warned += 1
            slug = record.get("title_slug", "<unknown>")
            missing = "problem_statement" if not has_stmt else "embedding_text"
            print(f"  [WARN] {slug}: missing '{missing}' — indexing with available fields")

        page_content = build_page_content(record)

        # Strips out heavy text fields before saving metadata.
        # This keeps the FAISS index lightweight and lightning fast.
        metadata = {
            k: v for k, v in record.items()
            if k not in ["embedding_text", "my_solution_code", "problem_statement"]
        }

        doc = Document(page_content=page_content, metadata=metadata)
        documents.append(doc)

    print(f"Indexed: {len(documents)}  |  Warned (partial): {warned}  |  Skipped (empty): {skipped}")

    # Compiles the final vector database.
    # FAISS organizes everything so we can do sub-millisecond similarity lookups.
    print(f"Building FAISS vectorstore with {len(documents)} documents. This may take a moment...")
    vectorstore = FAISS.from_documents(documents, embeddings)

    # Saves the compiled database to disk.
    # Next time, we can just load it instantly instead of recalculating embeddings.
    output_dir = "faiss_index"
    vectorstore.save_local(output_dir)
    print(f"Vectorstore successfully saved to {output_dir}/")
    print(f"Total documents indexed: {len(documents)}")


if __name__ == "__main__":
    build_vectorstore()
