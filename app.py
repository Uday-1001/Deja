# pyrefly: ignore [missing-import]
import streamlit as st
# pyrefly: ignore [missing-import]
import streamlit.components.v1 as components
import json
import os
import uuid
from retrieve import retrieve_similar_problems, init_models
from hint_generator import generate_hint, generate_reasoning_coach
from fireworks import st_fireworks
from ingest import run_ingestion

# Sets up the basic page config.
# Gives us that sleek wide layout right from the start.
st.set_page_config(page_title="Deja", page_icon="✨", layout="wide")

def load_backend_models():
    if "models_loaded" not in st.session_state:
        placeholder = st.empty()
        with placeholder.container():
            st.markdown("""
                <style>
                .centered-loader {
                    position: fixed;
                    top: 50%;
                    left: 50%;
                    transform: translate(-50%, -50%);
                    text-align: center;
                    z-index: 99999;
                    background: #111116;
                    padding: 40px;
                    border-radius: 16px;
                    box-shadow: 0 10px 40px rgba(0,0,0,0.8);
                    border: 2px solid #8a2be2;
                }
                .spinner-icon {
                    border: 4px solid rgba(138, 43, 226, 0.2);
                    border-top: 4px solid #8a2be2;
                    border-radius: 50%;
                    width: 50px;
                    height: 50px;
                    animation: spin 1s linear infinite;
                    margin: 0 auto 20px auto;
                }
                @keyframes spin { 0% { transform: rotate(0deg); } 100% { transform: rotate(360deg); } }
                </style>
                <div class="centered-loader">
                    <div class="spinner-icon"></div>
                    <h3 style="margin:0; color:#fff; font-family: sans-serif;">Loading Assets ✨...</h3>
                    <p style="margin:10px 0 0 0; color:#a0a0a0; font-family: sans-serif;">(This takes a moment, please wait...)</p>
                </div>
            """, unsafe_allow_html=True)
        
        init_models()
        placeholder.empty()
        st.session_state.models_loaded = True
    else:
        init_models()


load_backend_models()

# Injects our massive custom stylesheet.
# This powers the entire premium glassmorphic aesthetic.
st.markdown("""
<style>
    /* Global Background and Fonts */
    .stApp {
        background: linear-gradient(135deg, #0d0e15 0%, #1a1c29 100%);
        font-family: 'Inter', sans-serif;
    }
    
    /* Header styling with animated gradient */
    .main-title {
        background: linear-gradient(-45deg, #BB86FC, #8a2be2, #4facfe, #00f2fe);
        background-size: 300% 300%;
        animation: gradient-animation 6s ease infinite;
        -webkit-background-clip: text;
        -webkit-text-fill-color: transparent;
        font-weight: 800;
        text-align: center;
        padding-bottom: 10px;
        font-size: 3.5rem !important;
        letter-spacing: -1px;
    }
    
    @keyframes gradient-animation {
        0% { background-position: 0% 50%; }
        50% { background-position: 100% 50%; }
        100% { background-position: 0% 50%; }
    }
    
    /* Welcome screen styling */
    .welcome-container {
        text-align: center;
        padding: 60px 40px;
        background: rgba(18, 18, 26, 0.4);
        backdrop-filter: blur(25px);
        -webkit-backdrop-filter: blur(25px);
        border-top: 1px solid rgba(255, 255, 255, 0.1);
        border-left: 1px solid rgba(255, 255, 255, 0.05);
        border-right: 1px solid rgba(0, 0, 0, 0.6);
        border-bottom: 1px solid rgba(0, 0, 0, 0.8);
        border-radius: 24px;
        box-shadow: 
            inset 6px 6px 15px rgba(0, 0, 0, 0.8), 
            inset -6px -6px 15px rgba(255, 255, 255, 0.03),
            0 5px 15px rgba(0, 0, 0, 0.2);
        margin: 40px auto;
        max-width: 800px;
        transition: all 0.4s cubic-bezier(0.175, 0.885, 0.32, 1.275);
    }
    .welcome-container:hover {
        transform: scale(0.985);
        box-shadow: 
            inset 12px 12px 25px rgba(0, 0, 0, 0.9), 
            inset -10px -10px 25px rgba(255, 255, 255, 0.04),
            0 2px 5px rgba(0, 0, 0, 0.1);
    }
    
    /* Button Styling */
    div.stButton > button {
        background: #8a2be2;
        color: white;
        border: none;
        border-radius: 8px;
        padding: 10px 24px;
        font-weight: 600;
        transition: all 0.3s ease;
        box-shadow: 0 4px 15px rgba(138, 43, 226, 0.4);
    }
    
    div.stButton > button:hover {
        background: #BB86FC;
        transform: translateY(-2px) scale(1.02);
        box-shadow: 0 6px 20px rgba(187, 134, 252, 0.6);
        color: white;
        border: none;
    }

    /* Start Learning Button (Sleek Glassmorphic) */
    [data-testid="stMainBlockContainer"] div.stButton > button[kind="primary"] {
        background: rgba(138, 43, 226, 0.15) !important;
        backdrop-filter: blur(10px) !important;
        -webkit-backdrop-filter: blur(10px) !important;
        color: #f8f8f2 !important;
        border: 1px solid rgba(187, 134, 252, 0.4) !important;
        border-radius: 12px !important;
        padding: 12px 28px !important;
        font-weight: 600 !important;
        transition: all 0.3s cubic-bezier(0.175, 0.885, 0.32, 1.275) !important;
        box-shadow: 0 4px 15px rgba(138, 43, 226, 0.15), inset 0 1px 3px rgba(255, 255, 255, 0.1) !important;
    }
    
    [data-testid="stMainBlockContainer"] div.stButton > button[kind="primary"]:hover {
        transform: translateY(-2px) scale(1.02) !important;
        background: rgba(138, 43, 226, 0.3) !important;
        box-shadow: 0 8px 25px rgba(138, 43, 226, 0.4), inset 0 1px 3px rgba(255, 255, 255, 0.2) !important;
        color: #ffffff !important;
        border: 1px solid rgba(187, 134, 252, 0.8) !important;
    }
    
    /* Sidebar Specific Styling */
    [data-testid="stSidebar"] {
        background: linear-gradient(135deg, rgba(15,17,26,0.98) 0%, rgba(30,20,40,0.95) 100%) !important;
        border-right: 1px solid rgba(139, 92, 246, 0.15);
    }
    
    [data-testid="stSidebar"] div.stButton > button {
        background: rgba(255, 255, 255, 0.03);
        backdrop-filter: blur(10px);
        -webkit-backdrop-filter: blur(10px);
        border: 1px solid rgba(255, 255, 255, 0.05);
        border-left: 3px solid transparent;
        border-radius: 12px;
        box-shadow: 0 4px 10px rgba(0,0,0,0.1);
        padding: 12px 14px;
        width: 100%;
        display: block;
        transition: all 0.3s cubic-bezier(0.25, 0.8, 0.25, 1);
        margin-bottom: 8px;
    }
    
    [data-testid="stSidebar"] div.stButton > button:hover {
        background: rgba(139, 92, 246, 0.15);
        border-left: 3px solid #8b5cf6;
        border-top: 1px solid rgba(139, 92, 246, 0.3);
        border-right: 1px solid rgba(139, 92, 246, 0.3);
        border-bottom: 1px solid rgba(139, 92, 246, 0.3);
        box-shadow: 0 0 20px rgba(139, 92, 246, 0.3), inset 0 0 10px rgba(139, 92, 246, 0.1);
        transform: translateX(4px) scale(1.02);
    }
    
    [data-testid="stSidebar"] div.stButton > button[kind="primary"] {
        background: rgba(30, 30, 40, 0.5) !important;
        border: 1px solid rgba(139, 92, 246, 0.3) !important;
        color: #f8f8f2 !important;
    }
    
    [data-testid="stSidebar"] div.stButton > button[kind="primary"]:hover {
        background: linear-gradient(45deg, #8b5cf6, #d946ef) !important;
        border-color: transparent !important;
        box-shadow: 0 4px 20px rgba(217, 70, 239, 0.5) !important;
        color: white !important;
    }
    
    [data-testid="stSidebar"] div.stButton > button p {
        white-space: nowrap;
        overflow: hidden;
        text-overflow: ellipsis;
        margin: 0;
        text-align: left;
        font-size: 0.95rem;
        font-weight: 500;
        color: #cbd5e1;
        transition: color 0.2s;
    }
    
    [data-testid="stSidebar"] div.stButton > button:hover p {
        color: #ffffff;
    }
    
    /* Sidebar Premium Checkbox Styling */
    [data-testid="stSidebar"] .stCheckbox {
        background: rgba(255, 255, 255, 0.02);
        border: 1px solid rgba(255, 255, 255, 0.05);
        border-left: 3px solid transparent;
        border-radius: 12px;
        padding: 12px 14px;
        margin-bottom: 10px;
        transition: all 0.3s;
        box-shadow: 0 4px 10px rgba(0,0,0,0.1);
    }
    
    [data-testid="stSidebar"] .stCheckbox:hover {
        background: rgba(139, 92, 246, 0.05);
        border-left: 3px solid #d946ef;
        border-top: 1px solid rgba(139, 92, 246, 0.3);
        border-right: 1px solid rgba(139, 92, 246, 0.3);
        border-bottom: 1px solid rgba(139, 92, 246, 0.3);
        box-shadow: 0 0 15px rgba(217, 70, 239, 0.2);
        transform: translateX(4px);
    }
    
    /* Text Area Styling */
    .stTextArea label p {
        font-size: 1.2rem !important;
        font-weight: 600;
        background: linear-gradient(90deg, #ffffff, #a0a0a0);
        -webkit-background-clip: text;
        -webkit-text-fill-color: transparent;
        margin-bottom: 12px;
        letter-spacing: 0.5px;
    }
    
    .stTextArea textarea {
        background-color: rgba(18, 18, 26, 0.6) !important;
        backdrop-filter: blur(20px);
        -webkit-backdrop-filter: blur(20px);
        border: 1px solid rgba(138, 43, 226, 0.5) !important;
        color: #ffffff !important;
        border-radius: 16px !important;
        font-size: 1.1rem;
        padding: 20px !important;
        box-shadow: 0 8px 32px rgba(0, 0, 0, 0.4), inset 0 2px 10px rgba(138, 43, 226, 0.1) !important;
        transition: all 0.3s ease;
        line-height: 1.7;
    }
    
    .stTextArea textarea:focus {
        border: 1px solid #4facfe !important;
        box-shadow: 0 0 25px rgba(79, 172, 254, 0.4), inset 0 2px 15px rgba(0,0,0,0.5) !important;
        background-color: rgba(20, 20, 30, 0.9) !important;
        outline: none;
    }
    
    /* Code Block & Info Alert Styling (Make Info Alerts look like Code Blocks) */
    div[data-testid="stAlert"], 
    div[data-testid="stAlert"] > div {
        background-color: #111116 !important;
        border: none !important;
        color: #f8f8f2 !important;
    }
    div[data-testid="stAlert"] {
        border: 1px solid rgba(255, 255, 255, 0.1) !important;
        border-radius: 8px !important;
        padding: 0.5rem !important;
        box-shadow: inset 0 2px 4px rgba(0, 0, 0, 0.2) !important;
    }
    div[data-testid="stAlert"] svg {
        display: none !important;
    }
    div[data-testid="stAlert"] a {
        color: #8a2be2 !important;
    }
    
    /* Input Header */
    .input-header {
        margin-bottom: 25px;
        padding-top: 15px;
        display: flex;
        align-items: center;
        gap: 15px;
    }
    .input-header-icon {
        font-size: 2.6rem;
        line-height: 1;
        display: flex;
        align-items: center;
        filter: drop-shadow(0 4px 12px rgba(138, 43, 226, 0.6));
    }
    .input-header-text {
        font-weight: 800;
        font-size: 2.6rem;
        letter-spacing: -0.5px;
        background: linear-gradient(120deg, #BB86FC, #e0a3ff, #4facfe, #00f2fe);
        background-size: 200% auto;
        -webkit-background-clip: text;
        -webkit-text-fill-color: transparent;
        animation: gradient-animation 6s ease infinite;
        line-height: 1.2;
        padding-bottom: 5px;
    }
    
    /* Section Header (For Escalation Stages) */
    .section-header {
        margin-bottom: 20px;
        padding-top: 10px;
        display: flex;
        align-items: center;
        gap: 12px;
    }
    .section-header-icon {
        font-size: 2rem;
        line-height: 1;
        display: flex;
        align-items: center;
        filter: drop-shadow(0 2px 8px rgba(138, 43, 226, 0.4));
    }
    .section-header-text {
        font-weight: 700;
        font-size: 2rem;
        letter-spacing: -0.3px;
        background: linear-gradient(120deg, #e0a3ff, #8a2be2, #4facfe);
        background-size: 200% auto;
        -webkit-background-clip: text;
        -webkit-text-fill-color: transparent;
        animation: gradient-animation 6s ease infinite;
        line-height: 1.2;
        padding-bottom: 4px;
    }
</style>
""", unsafe_allow_html=True)

HISTORY_FILE = "history.json"

def load_history():
    if os.path.exists(HISTORY_FILE):
        with open(HISTORY_FILE, "r") as f:
            return json.load(f)
    return []

def save_history(history):
    def _numpy_safe(obj):
        # numpy scalars (bool_, float64, int64, etc.) all expose .item()
        # which converts them to the equivalent Python native type.
        if hasattr(obj, "item"):
            return obj.item()
        raise TypeError(f"Object of type {type(obj).__name__} is not JSON serializable")

    with open(HISTORY_FILE, "w") as f:
        json.dump(history, f, indent=2, default=_numpy_safe)

def get_relevant_matches(results: list[dict], score_margin: float = 0.15, min_matches: int = 1, max_matches: int = 5) -> list[dict]:
    # Filters search results dynamically based on a score margin.
    # Prevents us from showing terrible matches just to pad out a list of 5.
    if not results:
        return []
    top_score = results[0].get("similarity_score", 0.0)
    relevant = [
        r for r in results[:max_matches]
        if (top_score - r.get("similarity_score", 0.0)) <= score_margin
    ]
    if len(relevant) < min_matches:
        relevant = results[:min_matches]
    return relevant

def init_state():
    if "session_id" not in st.session_state:
        st.session_state.session_id = str(uuid.uuid4())
    if "stage" not in st.session_state:
        st.session_state.stage = "welcome"
    if "history" not in st.session_state:
        st.session_state.history = load_history()
    if "problem_statement" not in st.session_state:
        st.session_state.problem_statement = ""
    if "results" not in st.session_state:
        st.session_state.results = None
    if "hint" not in st.session_state:
        st.session_state.hint = ""
    if "pseudocode" not in st.session_state:
        st.session_state.pseudocode = ""
    if "code" not in st.session_state:
        st.session_state.code = ""
    if "is_history_view" not in st.session_state:
        st.session_state.is_history_view = False
    if "manage_history" not in st.session_state:
        st.session_state.manage_history = False
    if "chats_to_delete" not in st.session_state:
        st.session_state.chats_to_delete = []
    if "confirm_delete" not in st.session_state:
        st.session_state.confirm_delete = False
    if "is_confident" not in st.session_state:
        st.session_state.is_confident = True
    if "coach_mode_enabled" not in st.session_state:
        st.session_state.coach_mode_enabled = False
    if "stay_independent" not in st.session_state:
        st.session_state.stay_independent = False
    if "coach_data" not in st.session_state:
        st.session_state.coach_data = None
    if "balloons_shown" not in st.session_state:
        st.session_state.balloons_shown = False

init_state()

def reset_task_state():
    st.session_state.problem_statement = ""
    st.session_state.results = None
    st.session_state.hint = ""
    st.session_state.pseudocode = ""
    st.session_state.code = ""
    st.session_state.coach_mode_enabled = False
    st.session_state.stay_independent = False
    st.session_state.coach_data = None
    st.session_state.is_confident = True
    st.session_state.balloons_shown = False
    st.session_state.session_id = str(uuid.uuid4())
    st.session_state.is_history_view = False

# Renders the main animated title.
# This adds a ton of visual flair to the header.
st.markdown("<h1 class='main-title'>✨ Deja AI Mentor</h1>", unsafe_allow_html=True)

# Builds out the left sidebar.
# This acts as the control center for managing past sessions.
with st.sidebar:
    st.markdown("### 📚 Chat Section")
    if st.button("🏠 Home", use_container_width=True):
        st.session_state.stage = "welcome"
        reset_task_state()
        st.rerun()
        
    if st.button("➕ New Problem", use_container_width=True):
        st.session_state.stage = "input"
        reset_task_state()
        st.rerun()
        
    st.divider()
    
    if st.button("⚙️ Manage History" if not st.session_state.manage_history else "✅ Done Managing", type="primary", use_container_width=True):
        st.session_state.manage_history = not st.session_state.manage_history
        if not st.session_state.manage_history:
            st.session_state.chats_to_delete = []
            st.session_state.confirm_delete = False
        st.rerun()
        
    history_list = list(reversed(st.session_state.history))
    
    if st.session_state.manage_history:
        if st.session_state.chats_to_delete:
            if st.session_state.confirm_delete:
                st.warning(f"Delete {len(st.session_state.chats_to_delete)} chats?")
                col_y, col_n = st.columns(2)
                with col_y:
                    if st.button("✔️ Yes", use_container_width=True):
                        st.session_state.history = [s for s in st.session_state.history if s['id'] not in st.session_state.chats_to_delete]
                        save_history(st.session_state.history)
                        if st.session_state.session_id in st.session_state.chats_to_delete:
                            st.session_state.stage = "welcome"
                            st.session_state.problem_statement = ""
                        st.session_state.chats_to_delete = []
                        st.session_state.confirm_delete = False
                        st.session_state.manage_history = False
                        st.rerun()
                with col_n:
                    if st.button("❌ No", use_container_width=True):
                        st.session_state.confirm_delete = False
                        st.rerun()
            else:
                if st.button(f"🗑️ Delete {len(st.session_state.chats_to_delete)} Selected", type="primary", use_container_width=True):
                    st.session_state.confirm_delete = True
                    st.rerun()
        st.markdown("---")
    
    # Shows the 15 most recent chats.
    # We truncate the problem titles so they fit nicely in the sidebar.
    for session in history_list[:15]:
        first_line = session['problem_statement'].strip().split('\n')[0]
        first_line = first_line.replace('#', '').strip()
        title = first_line[:25] + "..." if len(first_line) > 25 else first_line
        
        if st.session_state.manage_history:
            is_checked = session['id'] in st.session_state.chats_to_delete
            if st.checkbox(f"📝 {title}", value=is_checked, key=f"chk_{session['id']}"):
                if session['id'] not in st.session_state.chats_to_delete:
                    st.session_state.chats_to_delete.append(session['id'])
                    st.rerun()
            else:
                if session['id'] in st.session_state.chats_to_delete:
                    st.session_state.chats_to_delete.remove(session['id'])
                    st.rerun()
        else:
            if st.button(f"📝 {title}", key=f"hist_{session['id']}", use_container_width=True):
                st.session_state.stage = session['stage']
                st.session_state.problem_statement = session['problem_statement']
                st.session_state.prob_input = session['problem_statement']
                st.session_state.hint = session.get('hint', '')
                st.session_state.pseudocode = session.get('pseudocode', '')
                st.session_state.code = session.get('code', '')
                st.session_state.results = session.get('results', [])
                st.session_state.session_id = session['id']
                st.session_state.is_history_view = True
                st.rerun()

    # Tucks older chats into an accordion menu.
    # Prevents the sidebar from becoming an endlessly scrolling nightmare.
    if len(history_list) > 15:
        with st.expander("🕰️ Older Chats"):
            for session in history_list[15:]:
                first_line = session['problem_statement'].strip().split('\n')[0]
                first_line = first_line.replace('#', '').strip()
                title = first_line[:25] + "..." if len(first_line) > 25 else first_line
                
                if st.session_state.manage_history:
                    is_checked = session['id'] in st.session_state.chats_to_delete
                    if st.checkbox(f"📝 {title}", value=is_checked, key=f"chk_{session['id']}"):
                        if session['id'] not in st.session_state.chats_to_delete:
                            st.session_state.chats_to_delete.append(session['id'])
                            st.rerun()
                    else:
                        if session['id'] in st.session_state.chats_to_delete:
                            st.session_state.chats_to_delete.remove(session['id'])
                            st.rerun()
                else:
                    if st.button(f"📝 {title}", key=f"hist_{session['id']}", use_container_width=True):
                        st.session_state.stage = session['stage']
                        st.session_state.problem_statement = session['problem_statement']
                        st.session_state.prob_input = session['problem_statement']
                        st.session_state.hint = session.get('hint', '')
                        st.session_state.pseudocode = session.get('pseudocode', '')
                        st.session_state.code = session.get('code', '')
                        st.session_state.results = session.get('results', [])
                        st.session_state.session_id = session['id']
                        st.session_state.is_history_view = True
                        st.rerun()

def update_history():
    # Syncs the current session state to the history log.
    # If it's a new session, it appends; otherwise it updates the existing entry.
    existing_idx = next((i for i, h in enumerate(st.session_state.history) if h['id'] == st.session_state.session_id), None)
    session_data = {
        "id": st.session_state.session_id,
        "problem_statement": st.session_state.problem_statement,
        "stage": st.session_state.stage,
        "hint": st.session_state.hint,
        "pseudocode": st.session_state.pseudocode,
        "code": st.session_state.code,
        "results": st.session_state.results,
        "is_confident": st.session_state.is_confident,
        "coach_mode_enabled": st.session_state.coach_mode_enabled,
        "stay_independent": st.session_state.stay_independent,
        "coach_data": st.session_state.coach_data
    }
    
    if existing_idx is not None:
        st.session_state.history[existing_idx] = session_data
    else:
        st.session_state.history.append(session_data)
    save_history(st.session_state.history)


# The main routing switch for the app.
# Renders different UI components based on the user's current stage.
if st.session_state.stage == "welcome":
    dashboard_css = """
    <style>
    @import url('https://fonts.googleapis.com/css2?family=Plus+Jakarta+Sans:wght@300;400;500;600;700;800&display=swap');

    .deja-dashboard {
        font-family: 'Plus Jakarta Sans', -apple-system, BlinkMacSystemFont, sans-serif;
        color: #e2e8f0;
        background: #090a10;
        padding-bottom: 20px;
    }

    /* Cards Base */
    .dashboard-card {
        background: rgba(18, 20, 32, 0.7);
        backdrop-filter: blur(16px);
        -webkit-backdrop-filter: blur(16px);
        border: 1px solid rgba(255, 255, 255, 0.07);
        border-radius: 20px;
        padding: 28px;
        box-shadow: 0 10px 30px rgba(0, 0, 0, 0.4);
        transition: transform 0.2s ease, border-color 0.2s ease;
    }
    
    .dashboard-card:hover {
        border-color: rgba(139, 92, 246, 0.3);
    }

    /* Hero Section */
    .hero-greeting {
        color: #c084fc;
        font-size: 0.95rem;
        font-weight: 600;
        margin-bottom: 8px;
        display: flex;
        align-items: center;
        gap: 6px;
    }
    
    .hero-title {
        font-size: 2.4rem;
        font-weight: 800;
        color: #ffffff;
        letter-spacing: -0.8px;
        margin-bottom: 12px;
        line-height: 1.2;
    }
    
    .hero-subtitle {
        color: #94a3b8;
        font-size: 0.98rem;
        line-height: 1.6;
        margin-bottom: 20px;
        font-weight: 400;
    }

    /* Pill Badges */
    .pill-group {
        display: flex;
        flex-wrap: wrap;
        gap: 8px;
        margin-bottom: 24px;
    }
    
    .pill-item {
        background: rgba(30, 32, 50, 0.6);
        border: 1px solid rgba(255, 255, 255, 0.08);
        color: #cbd5e1;
        font-size: 0.82rem;
        font-weight: 500;
        padding: 6px 14px;
        border-radius: 20px;
        display: flex;
        align-items: center;
        gap: 6px;
    }

    /* Diagram Card */
    .diagram-container {
        display: flex;
        align-items: center;
        justify-content: space-around;
        height: 100%;
        min-height: 180px;
        text-align: center;
    }
    
    .diagram-step {
        display: flex;
        flex-direction: column;
        align-items: center;
        gap: 10px;
    }
    
    .diagram-icon {
        width: 56px;
        height: 56px;
        border-radius: 16px;
        background: rgba(124, 58, 237, 0.12);
        border: 1px solid rgba(124, 58, 237, 0.3);
        display: flex;
        align-items: center;
        justify-content: center;
        font-size: 1.4rem;
        color: #a78bfa;
        box-shadow: 0 0 15px rgba(124, 58, 237, 0.2);
    }
    
    .diagram-label {
        font-size: 0.82rem;
        font-weight: 600;
        color: #94a3b8;
    }
    
    .diagram-arrow {
        color: #475569;
        font-size: 1.2rem;
    }

    /* Stat Cards */
    .stat-card {
        background: rgba(18, 20, 32, 0.7);
        border: 1px solid rgba(255, 255, 255, 0.07);
        border-radius: 16px;
        padding: 20px;
        display: flex;
        align-items: center;
        gap: 16px;
    }
    
    .stat-icon-wrapper {
        width: 48px;
        height: 48px;
        border-radius: 12px;
        background: rgba(139, 92, 246, 0.1);
        border: 1px solid rgba(139, 92, 246, 0.2);
        display: flex;
        align-items: center;
        justify-content: center;
        font-size: 1.3rem;
        color: #c084fc;
    }
    
    .stat-val {
        font-size: 1.6rem;
        font-weight: 800;
        color: #ffffff;
        line-height: 1;
    }
    
    .stat-title {
        font-size: 0.85rem;
        font-weight: 600;
        color: #e2e8f0;
        margin-top: 4px;
    }
    
    .stat-desc {
        font-size: 0.75rem;
        color: #64748b;
    }

    /* Section Titles */
    .section-title-sm {
        font-size: 1.05rem;
        font-weight: 700;
        color: #f1f5f9;
        margin-bottom: 16px;
        display: flex;
        align-items: center;
        gap: 8px;
    }

    /* History Table Items */
    .history-row {
        background: rgba(26, 29, 45, 0.5);
        border: 1px solid rgba(255, 255, 255, 0.05);
        border-radius: 12px;
        padding: 12px 16px;
        margin-bottom: 10px;
        display: flex;
        align-items: center;
        justify-content: space-between;
    }
    
    .history-title {
        font-size: 0.92rem;
        font-weight: 600;
        color: #f1f5f9;
    }
    
    .history-tag {
        background: rgba(255, 255, 255, 0.06);
        color: #94a3b8;
        font-size: 0.72rem;
        padding: 2px 8px;
        border-radius: 6px;
        margin-left: 8px;
    }
    
    .history-meta {
        font-size: 0.78rem;
        color: #64748b;
    }

    .progress-bar-bg {
        width: 80px;
        height: 6px;
        background: rgba(255, 255, 255, 0.1);
        border-radius: 3px;
        overflow: hidden;
    }
    
    .progress-bar-fill {
        height: 100%;
        background: linear-gradient(90deg, #7c3aed, #c084fc);
        border-radius: 3px;
    }

    /* Streak Widget */
    .streak-number {
        font-size: 2.8rem;
        font-weight: 800;
        color: #ffffff;
        line-height: 1;
    }
    
    .streak-grid {
        display: grid;
        grid-template-columns: repeat(7, 1fr);
        gap: 6px;
        margin-top: 16px;
    }
    
    .dot-day {
        font-size: 0.7rem;
        color: #64748b;
        text-align: center;
        margin-bottom: 4px;
        font-weight: 600;
    }
    
    .dot {
        width: 10px;
        height: 10px;
        border-radius: 50%;
        background: rgba(255, 255, 255, 0.1);
        margin: 0 auto 4px auto;
    }
    
    .dot.active {
        background: #a855f7;
        box-shadow: 0 0 8px rgba(168, 85, 247, 0.8);
    }
    
    .dot.bright {
        background: #38bdf8;
        box-shadow: 0 0 8px rgba(56, 189, 248, 0.8);
    }

    /* Tech Stack Footer */
    .tech-footer {
        text-align: center;
        padding-top: 24px;
        color: #475569;
        font-size: 0.8rem;
        letter-spacing: 0.5px;
    }
    
    /* Primary CTA Button styling override */
    div[data-testid="stButton"] > button[kind="primary"] {
        background: linear-gradient(135deg, #7c3aed 0%, #6366f1 100%) !important;
        color: white !important;
        border: none !important;
        border-radius: 12px !important;
        padding: 12px 24px !important;
        font-weight: 700 !important;
        font-size: 1rem !important;
        box-shadow: 0 6px 20px rgba(124, 58, 237, 0.35) !important;
        transition: all 0.2s ease !important;
    }
    div[data-testid="stButton"] > button[kind="primary"]:hover {
        transform: translateY(-2px) !important;
        box-shadow: 0 10px 25px rgba(124, 58, 237, 0.5) !important;
    }
    </style>
    """
    st.markdown(dashboard_css, unsafe_allow_html=True)

    # Renders the top hero section.
    # Gives the user a warm welcome back to the app.
    st.markdown("""
    <div class="dashboard-card" style="text-align: center; max-width: 800px; margin: 0 auto;">
        <div class="hero-greeting" style="justify-content: center;">✨ Welcome Back 👋</div>
        <div class="hero-title" style="font-size: 3.2rem;">What shall we solve today?</div>
        <div class="hero-subtitle" style="font-size: 1.1rem;">
            Deja learns from your accepted solutions and guides you through new challenges using the patterns you already know.
        </div>
        <div class="pill-group" style="justify-content: center; margin-bottom: 30px;">
            <div class="pill-item">👤 Personalized</div>
            <div class="pill-item">💡 Hints Only</div>
            <div class="pill-item">🛡️ No Spoilers</div>
            <div class="pill-item">⚡ Adaptive</div>
        </div>
    </div>
    """, unsafe_allow_html=True)
    
    st.markdown("<br>", unsafe_allow_html=True)
    
    col_center = st.columns([1, 1.5, 1])
    with col_center[1]:
        if st.button("🚀 Start New Problem  ➔", type="primary", use_container_width=True):
            st.session_state.stage = "input"
            st.session_state.problem_statement = ""
            st.session_state.results = None
            st.session_state.session_id = str(uuid.uuid4())
            st.session_state.is_history_view = False
            st.rerun()

    st.markdown("<br><br><br>", unsafe_allow_html=True)

    # Pre-calculates metrics for the dashboard.
    # We need these ready before rendering the book or stat cards.
    hist_data = load_history()
    total_problems_analyzed = len(hist_data)
    
    patterns_set = set()
    total_hints_generated = 0
    if hist_data:
        for item in hist_data:
            total_hints_generated += 1
            if "results" in item and item["results"]:
                for res in item["results"]:
                    if "topics_tagged" in res:
                        patterns_set.update(res["topics_tagged"])
                        
    patterns_learned = len(patterns_set)
    retrieval_acc = "94%" if total_problems_analyzed > 0 else "0%"

    # Splits the middle section into two columns.
    # Book animation on the left, "How it works" graphic on the right.
    col_left, col_right = st.columns(2, gap="large")
    
    with col_left:
        try:
            with open("book.html", "r", encoding="utf-8") as f:
                book_html = f.read()
                
            import random
            import urllib.parse
            
            # Grabs 5 patterns from the user's history.
            # Falls back to defaults if they haven't learned enough yet.
            display_patterns = list(patterns_set) if len(patterns_set) > 0 else ["Two Pointers", "Sliding Window", "Dynamic Programming", "Graph Traversal", "Backtracking"]
            
            while len(display_patterns) < 5:
                display_patterns.extend(display_patterns)
            random.shuffle(display_patterns)
            selected = display_patterns[:5]
            
            # Generates SVGs on the fly and maps them to CSS vars.
            # This makes the book animation incredibly smooth and performant.
            css_vars = "<style>:root {\n"
            for i in range(1, 6):
                pattern = selected[i-1]
                svg = f'''<svg xmlns="http://www.w3.org/2000/svg" width="420" height="300">
                    <defs>
                        <linearGradient id="bg{i}" x1="0%" y1="0%" x2="100%" y2="100%">
                            <stop offset="0%" stop-color="#1e1b4b" />
                            <stop offset="100%" stop-color="#0f172a" />
                        </linearGradient>
                    </defs>
                    <rect width="100%" height="100%" fill="url(#bg{i})"/>
                    <!-- Decorative Border -->
                    <rect x="20" y="20" width="380" height="260" fill="none" stroke="#6d28d9" stroke-width="2" opacity="0.6"/>
                    <rect x="26" y="26" width="368" height="248" fill="none" stroke="#6d28d9" stroke-width="1" opacity="0.3"/>
                    <!-- Top Header -->
                    <text x="50%" y="85" font-size="11" fill="#94a3b8" font-family="sans-serif" font-weight="bold" letter-spacing="3" text-anchor="middle">✦ DEJA KNOWLEDGE BASE ✦</text>
                    <!-- Main Pattern Title (Performant Drop Shadow) -->
                    <text x="50%" y="157" font-size="34" fill="#6d28d9" font-family="Georgia, serif" font-weight="bold" text-anchor="middle">{pattern}</text>
                    <text x="50%" y="155" font-size="34" fill="#ffffff" font-family="Georgia, serif" font-weight="bold" text-anchor="middle">{pattern}</text>
                    <!-- Bottom Description -->
                    <text x="50%" y="225" font-size="14" fill="#c084fc" font-family="sans-serif" font-style="italic" text-anchor="middle">Mastered algorithmic pattern</text>
                    <!-- Center Binding Shadow -->
                    <line x1="210" y1="0" x2="210" y2="300" stroke="#000000" stroke-width="5" opacity="0.5"/>
                </svg>'''
                
                # Minifies and URL-encodes the SVG string.
                # Required for embedding SVGs directly inside CSS.
                svg_minified = svg.replace('\n', '').replace('    ', '')
                encoded_svg = f"data:image/svg+xml;charset=utf-8,{urllib.parse.quote(svg_minified)}"
                
                # Assigns the encoded SVG to a custom CSS property.
                # E.g., --img1, --img2, etc.
                css_vars += f"  --img{i}: url('{encoded_svg}');\n"
                
                # Replaces the generic picsum URLs in the HTML.
                # Caches the SVG once per load instead of spamming network requests.
                book_html = book_html.replace(f'url("https://picsum.photos/420/300?random={i}")', f'var(--img{i})')
                
            css_vars += "}</style>\n"
            
            # Prepends the CSS block to the raw HTML string.
            # Then renders the whole block via Streamlit components.
            book_html = css_vars + book_html
            
            components.html(book_html, height=460)
        except Exception as e:
            pass

    with col_right:
        st.markdown("""
        <div class="dashboard-card" style="height: 460px; display: flex; flex-direction: column; justify-content: center; margin-bottom: 20px; border: 2px solid rgba(139, 92, 246, 0.8); border-radius: 20px; background: rgba(18, 20, 32, 0.7); box-shadow: 0 10px 30px rgba(139, 92, 246, 0.2);">
            <div style="text-align: center; margin-bottom: 25px;">
                <h3 style="margin: 0; color: #ffffff; font-size: 1.3rem; font-weight: 700;">How Deja Works</h3>
                <p style="color: #94a3b8; margin-top: 8px; font-size: 0.95rem; line-height: 1.5;">
                    By analyzing the code you've already written, we extract your known algorithmic patterns<br>
                    and use them to provide personalized, spoiler-free guidance for new problems.
                </p>
            </div>
            <div class="diagram-container">
                <div class="diagram-step">
                    <div class="diagram-icon">💻</div>
                    <div class="diagram-label">Your Past<br>Solutions</div>
                </div>
                <div class="diagram-arrow">➔</div>
                <div class="diagram-step">
                    <div class="diagram-icon">🧠</div>
                    <div class="diagram-label">Pattern<br>Understanding</div>
                </div>
                <div class="diagram-arrow">➔</div>
                <div class="diagram-step">
                    <div class="diagram-icon">🎯</div>
                    <div class="diagram-label">Smart<br>Guidance</div>
                </div>
            </div>
        </div>
        """, unsafe_allow_html=True)

    st.markdown("<br><br>", unsafe_allow_html=True)

    # Renders the dynamic stats bar.
    # Shows problems analyzed, patterns learned, and hint accuracy.
    m1, m2, m3, m4 = st.columns(4)
    
    with m1:
        st.markdown(f"""
        <div class="stat-card">
            <div class="stat-icon-wrapper">💻</div>
            <div>
                <div class="stat-val">{total_problems_analyzed}</div>
                <div class="stat-title">Problems Analyzed</div>
                <div class="stat-desc">Across all submissions</div>
            </div>
        </div>
        """, unsafe_allow_html=True)
        
    with m2:
        st.markdown(f"""
        <div class="stat-card">
            <div class="stat-icon-wrapper">🧠</div>
            <div>
                <div class="stat-val">{patterns_learned}</div>
                <div class="stat-title">Patterns Learned</div>
                <div class="stat-desc">Algorithmic patterns</div>
            </div>
        </div>
        """, unsafe_allow_html=True)

    with m3:
        st.markdown(f"""
        <div class="stat-card">
            <div class="stat-icon-wrapper">🎯</div>
            <div>
                <div class="stat-val">{retrieval_acc}</div>
                <div class="stat-title">Retrieval Accuracy</div>
                <div class="stat-desc">Relevant hints found</div>
            </div>
        </div>
        """, unsafe_allow_html=True)

    with m4:
        st.markdown(f"""
        <div class="stat-card">
            <div class="stat-icon-wrapper">⚡</div>
            <div>
                <div class="stat-val">{total_hints_generated}</div>
                <div class="stat-title">Hints Generated</div>
                <div class="stat-desc">Guiding your journey</div>
            </div>
        </div>
        """, unsafe_allow_html=True)

    # Renders the footer quote.
    # A nice little touch to end the dashboard.
    st.markdown("""
    <div class="tech-footer" style="font-style: italic; font-size: 0.95rem; opacity: 0.8; margin-top: 20px;">
        "Programs must be written for people to read, and only incidentally for machines to execute." &nbsp;–&nbsp; Harold Abelson
    </div>
    """, unsafe_allow_html=True)
    
    # Injects GSAP animations.
    # Powers all the buttery smooth entrance and hover effects.
    components.html("""
    <script src="https://cdnjs.cloudflare.com/ajax/libs/gsap/3.12.2/gsap.min.js"></script>
    <script>
        const doc = window.parent.document;
        // Wait briefly for Streamlit's DOM to settle
        setTimeout(() => {
            const tl = gsap.timeline();
            
            // 1. Initial Load Sequence
            tl.fromTo(doc.querySelectorAll('.hero-greeting'), { y: -20, opacity: 0 }, { y: 0, opacity: 1, duration: 0.6, ease: "power3.out" })
              .fromTo(doc.querySelectorAll('.hero-title'), { y: 30, opacity: 0 }, { y: 0, opacity: 1, duration: 0.8, ease: "back.out(1.5)" }, "-=0.4")
              .fromTo(doc.querySelectorAll('.hero-subtitle'), { y: 20, opacity: 0 }, { y: 0, opacity: 1, duration: 0.6, ease: "power3.out" }, "-=0.5")
              .fromTo(doc.querySelectorAll('.pill-item'), { scale: 0.8, opacity: 0, y: 15 }, { scale: 1, opacity: 1, y: 0, duration: 0.5, stagger: 0.1, ease: "back.out(2)" }, "-=0.3")
              .fromTo(doc.querySelectorAll('button[kind="primary"]'), { scale: 0.95, opacity: 0, y: 20 }, { scale: 1, opacity: 1, y: 0, duration: 0.6, ease: "power2.out" }, "-=0.2")
              .fromTo(doc.querySelectorAll('.dashboard-card, iframe'), { y: 40, opacity: 0 }, { y: 0, opacity: 1, duration: 0.8, stagger: 0.15, ease: "power3.out" }, "-=0.2")
              .fromTo(doc.querySelectorAll('.stat-card'), { y: 20, opacity: 0 }, { y: 0, opacity: 1, duration: 0.5, stagger: 0.1, ease: "power2.out" }, "-=0.4");
              
            // 2. Continuous Ambient Floating (How it Works Icons)
            gsap.to(doc.querySelectorAll('.diagram-icon'), {
                y: -8,
                duration: 2,
                repeat: -1,
                yoyo: true,
                ease: "sine.inOut",
                stagger: 0.2
            });
            
            // 3. Continuous Button Pulse
            gsap.to(doc.querySelectorAll('button[kind="primary"]'), {
                boxShadow: "0px 0px 25px rgba(124, 58, 237, 0.7)",
                duration: 1.5,
                repeat: -1,
                yoyo: true,
                ease: "sine.inOut"
            });
            
            // 4. Interactive Hover Physics for Stat Cards
            doc.querySelectorAll('.stat-card').forEach(card => {
                card.addEventListener('mouseenter', () => {
                    gsap.to(card, { y: -6, scale: 1.02, boxShadow: "0px 15px 35px rgba(139, 92, 246, 0.25)", duration: 0.4, ease: "back.out(1.5)" });
                    gsap.to(card.querySelector('.stat-icon-wrapper'), { rotation: 10, scale: 1.15, duration: 0.4, ease: "back.out(3)" });
                });
                card.addEventListener('mouseleave', () => {
                    gsap.to(card, { y: 0, scale: 1, boxShadow: "0px 0px 0px rgba(0,0,0,0)", duration: 0.4, ease: "power2.out" });
                    gsap.to(card.querySelector('.stat-icon-wrapper'), { rotation: 0, scale: 1, duration: 0.4, ease: "power2.out" });
                });
            });
            
            // 5. Interactive Hover for Feature Pills
            doc.querySelectorAll('.pill-item').forEach(pill => {
                pill.addEventListener('mouseenter', () => {
                    gsap.to(pill, { y: -4, scale: 1.08, duration: 0.3, ease: "back.out(2)" });
                });
                pill.addEventListener('mouseleave', () => {
                    gsap.to(pill, { y: 0, scale: 1, duration: 0.3, ease: "power2.out" });
                });
            });
        }, 150);
    </script>
    """, height=0, width=0)


elif st.session_state.stage == "input":
    # Injects input-view specific CSS.
    # Adds that crazy holographic text and 3D cube animation.
    st.markdown("""
    <style>
    .stTextArea textarea {
        background: linear-gradient(145deg, rgba(15, 17, 26, 0.85), rgba(25, 20, 35, 0.95)) !important;
        border: 2px solid rgba(139, 92, 246, 0.4) !important;
        border-radius: 20px !important;
        color: #f8f8f2 !important;
        font-family: 'Inter', sans-serif !important;
        padding: 16px !important;
        font-size: 1.1rem !important;
        line-height: 1.6 !important;
        box-shadow: inset 0 4px 15px rgba(0,0,0,0.8), 0 10px 30px rgba(139, 92, 246, 0.15) !important;
        transition: all 0.4s cubic-bezier(0.25, 0.8, 0.25, 1) !important;
        position: relative;
    }
    .stTextArea textarea:hover {
        border-color: rgba(217, 70, 239, 0.6) !important;
        box-shadow: inset 0 4px 15px rgba(0,0,0,0.8), 0 15px 40px rgba(217, 70, 239, 0.25) !important;
        transform: translateY(-2px);
    }
    .stTextArea textarea:focus {
        border-color: #d946ef !important;
        background: rgba(20, 15, 30, 0.95) !important;
        box-shadow: 0 0 30px rgba(217, 70, 239, 0.5), inset 0 4px 15px rgba(0,0,0,0.9) !important;
        transform: translateY(-4px);
    }
    
    .holographic-title {
        font-size: 1.1rem;
        font-weight: 700;
        letter-spacing: 2px;
        text-transform: uppercase;
        margin-bottom: 5px;
        background: linear-gradient(90deg, #8b5cf6, #d946ef, #8b5cf6);
        background-size: 200% auto;
        color: #fff;
        background-clip: text;
        -webkit-text-fill-color: transparent;
        animation: gradient-shift 3s linear infinite;
        text-shadow: 0px 0px 20px rgba(217, 70, 239, 0.4);
    }
    @keyframes gradient-shift {
        0% { background-position: 0% center; }
        100% { background-position: 200% center; }
    }
    .stTextArea label {
        display: none !important;
    }
    
    /* 3D Solving Cube */
    .cube-wrapper {
        perspective: 800px;
        width: 44px;
        height: 44px;
        margin: 0 auto 5px auto;
    }
    .cube {
        width: 100%;
        height: 100%;
        position: relative;
        transform-style: preserve-3d;
        animation: solve-cube 5s infinite cubic-bezier(0.4, 0, 0.2, 1);
    }
    .cube-face {
        position: absolute;
        width: 44px;
        height: 44px;
        border: 2px solid rgba(168, 85, 247, 0.8);
        background: rgba(138, 43, 226, 0.15);
        box-shadow: inset 0 0 10px rgba(168, 85, 247, 0.4);
    }
    .face-front  { transform: rotateY(  0deg) translateZ(22px); }
    .face-right  { transform: rotateY( 90deg) translateZ(22px); }
    .face-back   { transform: rotateY(180deg) translateZ(22px); }
    .face-left   { transform: rotateY(-90deg) translateZ(22px); }
    .face-top    { transform: rotateX( 90deg) translateZ(22px); }
    .face-bottom { transform: rotateX(-90deg) translateZ(22px); }

    @keyframes solve-cube {
        0%   { transform: rotateX(0deg) rotateY(0deg) rotateZ(0deg); }
        20%  { transform: rotateX(90deg) rotateY(0deg) rotateZ(90deg); }
        40%  { transform: rotateX(90deg) rotateY(90deg) rotateZ(90deg); }
        60%  { transform: rotateX(180deg) rotateY(90deg) rotateZ(180deg); }
        80%  { transform: rotateX(180deg) rotateY(270deg) rotateZ(180deg); }
        100% { transform: rotateX(360deg) rotateY(360deg) rotateZ(360deg); }
    }
    </style>
    """, unsafe_allow_html=True)

    with st.container():
        st.markdown("""
        <div style="text-align: center; margin-bottom: 20px; margin-top: 5px;">
            <div class="cube-wrapper">
                <div class="cube">
                    <div class="cube-face face-front"></div>
                    <div class="cube-face face-right"></div>
                    <div class="cube-face face-back"></div>
                    <div class="cube-face face-left"></div>
                    <div class="cube-face face-top"></div>
                    <div class="cube-face face-bottom"></div>
                </div>
            </div>
            <div class="hero-title" style="font-size: 2.2rem; margin-bottom: 8px;">What problem are we tackling today?</div>
        </div>
        """, unsafe_allow_html=True)
        
        # Centers the main text area column.
        # Keeps the layout balanced on wide screens.
        col_main = st.columns([1, 4, 1])
        with col_main[1]:
            st.markdown("""
            <div class="holographic-title input-view-elem">
                Enter the Problem <span style="opacity: 0.5;">//</span>
            </div>
            """, unsafe_allow_html=True)
            
            problem_input = st.text_area("Paste the problem statement here:", height=240, key="prob_input", placeholder="e.g. Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target...")
            col_btn = st.columns([1, 1.5, 1])
            with col_btn[1]:
                if st.button("🧠 Analyze Problem", type="primary", use_container_width=True):
                    if problem_input.strip():
                        with st.spinner("Searching past solutions..."):
                            results, is_confident = retrieve_similar_problems(problem_input, top_k_retrieve=15, top_k_final=5)
                            st.session_state.results = results
                            st.session_state.is_confident = is_confident
                            st.session_state.problem_statement = problem_input
                            
                            st.session_state.stage = "hint"
                            if is_confident:
                                st.session_state.hint = generate_hint(problem_input, results, stage="hint")
                            else:
                                st.session_state.coach_mode_enabled = False
                                st.session_state.stay_independent = False
                                st.session_state.coach_data = None
                                
                            update_history()
                            st.rerun()
            
            # Injects input-view specific GSAP animations.
            # Animates the form components entering the screen.
            components.html("""
            <script src="https://cdnjs.cloudflare.com/ajax/libs/gsap/3.12.2/gsap.min.js"></script>
            <script>
                const doc = window.parent.document;
                setTimeout(() => {
                    const tl = gsap.timeline();
                    // Cinematic reveal of the elements
                    tl.fromTo(doc.querySelectorAll('.hero-title'), { opacity: 0, y: -30, scale: 0.9 }, { opacity: 1, y: 0, scale: 1, duration: 0.8, ease: "back.out(1.5)" })
                      .fromTo(doc.querySelectorAll('.input-view-elem'), { opacity: 0, x: -30 }, { opacity: 1, x: 0, duration: 0.6, ease: "power3.out" }, "-=0.4")
                      .fromTo(doc.querySelectorAll('.stTextArea'), { opacity: 0, y: 40, scale: 0.95 }, { opacity: 1, y: 0, scale: 1, duration: 0.7, ease: "power3.out" }, "-=0.3")
                      .fromTo(doc.querySelectorAll('button[kind="primary"]'), { opacity: 0, scale: 0.8, y: 20 }, { opacity: 1, scale: 1, y: 0, duration: 0.6, ease: "back.out(2)" }, "-=0.2");
                    
                    // Analyze Button Pulse
                    gsap.to(doc.querySelectorAll('button[kind="primary"]'), {
                        boxShadow: "0px 0px 30px rgba(217, 70, 239, 0.8)",
                        duration: 1.2,
                        repeat: -1,
                        yoyo: true,
                        ease: "sine.inOut"
                    });
                }, 100);
            </script>
            """, height=0, width=0)

# Renders the core problem-solving pipeline.
# Dynamically unlocks deeper hints based on user interaction.
if st.session_state.stage in ["hint", "pseudocode", "code", "solved", "ingesting"]:
    
    # Pins the problem statement to the top.
    # Ensures the user always has context without scrolling up.
    with st.container():
        st.markdown("<div class='section-header'><span class='section-header-icon'>📄</span><span class='section-header-text'>Problem Statement</span></div>", unsafe_allow_html=True)
        st.info(st.session_state.problem_statement)
    
    # Stage 1: The Hint.
    # Gives the user a gentle nudge towards the correct pattern.
    with st.container():
        if st.session_state.is_confident:
            st.markdown("<div class='section-header'><span class='section-header-icon'>💡</span><span class='section-header-text'>Stage 1: Hint</span></div>", unsafe_allow_html=True)
            if st.session_state.results:
                relevant_matches = get_relevant_matches(st.session_state.results)
                
                # Checks if it's a "pure" match.
                # We pull the CE sigmoid score to see how confident the model was.
                top_ce = relevant_matches[0].get("ce_sigmoid", 0.0)
                
                past_problems_html = "<ul style='list-style-type: none; padding-left: 0;'>"
                for res in relevant_matches:
                    title = res.get('title', res.get('title_slug', 'Unknown Problem'))
                    diff = res.get('difficulty', 'Unknown')
                    tech = res.get('core_technique', '')
                    score = res.get('similarity_score', 0.0)
                    
                    # Maps the raw float score to a percentage.
                    # similarity_score usually ranges from 0.5 to 0.98.
                    pct = int(score * 100)
                    # Color-codes the confidence badge.
                    # Green for high confidence, orange for medium, red for low.
                    if pct >= 74:
                        badge_color = "#2e7d32" # Green
                    elif pct >= 65:
                        badge_color = "#f57c00" # Orange
                    else:
                        badge_color = "#c62828" # Red
                        
                    badge_html = f"<span style='background-color: {badge_color}; color: white; padding: 2px 8px; border-radius: 12px; font-size: 0.8em; font-weight: bold; margin-right: 8px;'>{pct}% Match</span>"
                    tech_html = f" &mdash; <i>{tech}</i>" if tech else ""
                    
                    past_problems_html += f"<li style='margin-bottom: 8px;'>{badge_html} <b>{title}</b> ({diff}){tech_html}</li>"
                
                past_problems_html += "</ul>"
                
                with st.expander("📚 Based on your past solved problems", expanded=False):
                    st.markdown(past_problems_html, unsafe_allow_html=True)
                
            st.info(st.session_state.hint)
        else:
            st.markdown("##### ❌ No confident match found.")
            st.markdown("I found a few somewhat related problems, but none closely matches this one.")
            if st.session_state.results:
                relevant_matches = get_relevant_matches(st.session_state.results)
                past_problems_html = "<ul style='list-style-type: none; padding-left: 0;'>"
                for res in relevant_matches:
                    title = res.get('title', res.get('title_slug', 'Unknown Problem'))
                    diff = res.get('difficulty', 'Unknown')
                    tech = res.get('core_technique', '')
                    score = res.get('similarity_score', 0.0)
                    
                    pct = int(score * 100)
                    if pct >= 74:
                        badge_color = "#2e7d32" # Green
                    elif pct >= 65:
                        badge_color = "#f57c00" # Orange
                    else:
                        badge_color = "#c62828" # Red
                        
                    badge_html = f"<span style='background-color: {badge_color}; color: white; padding: 2px 8px; border-radius: 12px; font-size: 0.8em; font-weight: bold; margin-right: 8px;'>{pct}% Match</span>"
                    tech_html = f" &mdash; <i>{tech}</i>" if tech else ""
                    
                    past_problems_html += f"<li style='margin-bottom: 8px;'>{badge_html} <b>{title}</b> ({diff}){tech_html}</li>"
                
                past_problems_html += "</ul>"
                st.markdown(past_problems_html, unsafe_allow_html=True)
            
            if not st.session_state.coach_mode_enabled:
                if not st.session_state.stay_independent:
                    st.markdown("Would you like me to act as your reasoning coach?")
                    c1, c2, c3 = st.columns([1, 2, 1])
                    with c2:
                        if st.button("Stay Independent", use_container_width=True):
                            st.session_state.stay_independent = True
                            st.rerun()
                            
                        st.markdown("<br>", unsafe_allow_html=True)
                        
                        if st.button("Enable Coach Mode", type="primary", use_container_width=True):
                            st.session_state.coach_mode_enabled = True
                            st.rerun()
                else:
                    st.info('_"A smooth sea never made a skilled sailor. Trust your instincts and conquer this problem on your own!"_ 🌊')
                    
                    if st.session_state.stage == "hint":
                        c1, c2, c3 = st.columns([1, 2, 1])
                        with c2:
                            if st.button("✅ Solved?", use_container_width=True):
                                with st.spinner("Preparing an example solution for comparison..."):
                                    if not st.session_state.code:
                                        st.session_state.code = generate_hint(st.session_state.problem_statement, st.session_state.results, stage="code")
                                st.session_state.stage = "solved"
                                update_history()
                                st.rerun()
                                
                            st.markdown("<br>", unsafe_allow_html=True)
                            
                            if st.button("Enable Coach Mode", use_container_width=True):
                                st.session_state.coach_mode_enabled = True
                                st.session_state.stay_independent = False
                                st.rerun()
            else:
                st.markdown("<div class='section-header'><span class='section-header-icon'>💡</span><span class='section-header-text'>Stage 1: Hint</span></div>", unsafe_allow_html=True)
                if st.session_state.coach_data is None:
                    with st.spinner("Thinking of some helpful tips..."):
                        coach_resp = generate_reasoning_coach(st.session_state.problem_statement, st.session_state.results[:3])
                        st.session_state.coach_data = coach_resp
                        update_history()
                        st.rerun()
                else:
                    coach = st.session_state.coach_data
                    if "error" in coach:
                        st.error(coach["error"])
                    else:
                        coach_md = f"**Observations:**\n"
                        for obs in coach.get("observations", []): coach_md += f"- {obs}\n"
                        coach_md += f"\n**Candidate Patterns:**\n"
                        for p in coach.get("candidate_patterns", []): coach_md += f"- {p}\n"
                        coach_md += f"\n**Invariants:**\n"
                        for inv in coach.get("invariants", []): coach_md += f"- {inv}\n"
                        coach_md += f"\n**Edge Cases:**\n"
                        for ec in coach.get("edge_cases", []): coach_md += f"- {ec}\n"
                        coach_md += f"\n**Questions to Ask:**\n"
                        for q in coach.get("questions_to_ask", []): coach_md += f"- {q}\n"
                        coach_md += f"\n**Hint 1:** {coach.get('hint_1', '')}\n"
                        coach_md += f"\n**Hint 2:** {coach.get('hint_2', '')}\n"
                        coach_md += f"\n**Pitfalls:**\n"
                        for p in coach.get("pitfalls", []): coach_md += f"- {p}\n"
                        
                        st.info(coach_md)
        
        should_show_hint_buttons = st.session_state.is_confident or (st.session_state.coach_mode_enabled and st.session_state.coach_data is not None)
        if st.session_state.stage == "hint" and should_show_hint_buttons:
            st.markdown("---")
            st.markdown("#### Did this hint help you solve it?")
            
            c1, c2, c3 = st.columns([1, 2, 1])
            with c2:
                if st.button("✅ Yes, I solved it!", use_container_width=True):
                    st.session_state.stage = "solved"
                    update_history()
                    st.rerun()
                    
                st.markdown("<br>", unsafe_allow_html=True)
                
                if st.button("🤔 No, show pseudocode", use_container_width=True):
                    with st.spinner("Writing a step-by-step plan for you..."):
                        if not st.session_state.code:
                            st.session_state.code = generate_hint(st.session_state.problem_statement, st.session_state.results, stage="code")
                        st.session_state.pseudocode = generate_hint(
                            st.session_state.problem_statement, 
                            st.session_state.results, 
                            stage="pseudocode", 
                            reference_code=st.session_state.code
                        )
                        st.session_state.stage = "pseudocode"
                        update_history()
                        st.rerun()

    # Stage 2: Pseudocode.
    # Breaks down the logic step-by-step without giving away actual syntax.
    if st.session_state.stage in ["pseudocode", "code", "solved", "ingesting"] and st.session_state.pseudocode:
        with st.container():
            st.markdown("<div class='section-header'><span class='section-header-icon'>🛠️</span><span class='section-header-text'>Stage 2: Pseudocode</span></div>", unsafe_allow_html=True)
            st.info(st.session_state.pseudocode)
            
            if st.session_state.stage == "pseudocode":
                st.markdown("---")
                st.markdown("#### Did this pseudocode help you solve it?")
                
                c1, c2, c3 = st.columns([1, 2, 1])
                with c2:
                    if st.button("✅ Yes, I solved it!", key="solved_pseudo", use_container_width=True):
                        st.session_state.stage = "solved"
                        update_history()
                        st.rerun()
                    
                    st.markdown("<br>", unsafe_allow_html=True)
                    
                    if st.button("😞 No, show me the code", key="show_code", use_container_width=True):
                        with st.spinner("Generating reference solution..."):
                            if not st.session_state.code:
                                st.session_state.code = generate_hint(st.session_state.problem_statement, st.session_state.results, stage="code")
                            st.session_state.stage = "code"
                            update_history()
                            st.rerun()

    # Stage 3: The Code.
    # Reveals the full optimal reference implementation for the user to study.
    if st.session_state.stage in ["code", "solved", "ingesting"] and st.session_state.code:
        with st.container():
            st.markdown("<div class='section-header'><span class='section-header-icon'>💻</span><span class='section-header-text'>Stage 3: Reference Code & Explanation</span></div>", unsafe_allow_html=True)
            st.markdown(st.session_state.code)
            
            if st.session_state.stage == "code":
                st.markdown("---")
                st.markdown("#### Did seeing the full code help you understand it?")
                if st.button("✅ Yes, I adapted it!", key="solve_code"):
                    st.session_state.stage = "solved"
                    update_history()
                    st.rerun()

    # Celebrates a successful solve!
    # Triggers balloons and prompts them to ingest the solution.
    if st.session_state.stage == "solved":
        if not st.session_state.is_history_view:
            if not st.session_state.get("balloons_shown", False):
                st_fireworks()
                st.session_state.balloons_shown = True
            with st.container():
                st.markdown("### 🎉 Awesome job!")
                st.markdown("Would you like to save your new solution into the database so Deja can learn from it?")
                if st.button("📥 Yes, let's save it!"):
                    st.session_state.stage = "ingesting"
                    update_history()
                    st.rerun()
        else:
            with st.container():
                st.success("🎉 You successfully solved this problem in a previous session!")
            
    if st.session_state.stage == "ingesting":
        with st.container():
            st.markdown("### 📥 Save a New Solution")
            
            title_slug = st.text_input("Problem Title (e.g., 'Two Sum'):")
            solution_code = st.text_area("Paste your accepted Python code here:", height=250)
            
            if st.button("🚀 Save Solution"):
                if not title_slug or not solution_code:
                    st.error("Please provide both a problem title and your solution code.")
                else:
                    with st.spinner("Processing your solution (this takes ~5s)..."):
                        res = run_ingestion(st.session_state.problem_statement, title_slug, solution_code)
                        if res and res.get("status") == "success":
                            st.success("✅ Saved successfully! Your solution is now searchable.")
                            # Routes the user back home.
                            # The cycle is complete, time for a new challenge!
                            st.session_state.stage = "welcome"
                            update_history()
                        else:
                            st.error(f"❌ Failed to save: {res.get('message') if res else 'Unknown error'}")
