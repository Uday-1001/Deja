# pyrefly: ignore [missing-import]
import streamlit as st
import json
import os
import uuid
from retrieve import retrieve_similar_problems, init_models
from hint_generator import generate_hint, generate_reasoning_coach
from fireworks import st_fireworks
from ingest import run_ingestion

# Set up the browser tab and page layout right away
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

# Inject our custom stylesheet to give the app its premium glassmorphic aesthetic
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
        background-color: rgba(20, 20, 30, 0.9) !important;
        border-right: 1px solid rgba(187, 134, 252, 0.2);
    }
    
    [data-testid="stSidebar"] div.stButton > button {
        background: rgba(30, 30, 42, 0.4);
        backdrop-filter: blur(10px);
        -webkit-backdrop-filter: blur(10px);
        border: 1px solid rgba(255, 255, 255, 0.05);
        border-left: 3px solid transparent;
        border-radius: 8px;
        box-shadow: 0 4px 10px rgba(0,0,0,0.2);
        padding: 12px 14px;
        width: 100%;
        display: block;
        transition: all 0.2s cubic-bezier(0.25, 0.8, 0.25, 1);
        margin-bottom: 2px;
    }
    
    [data-testid="stSidebar"] div.stButton > button:hover {
        background: rgba(138, 43, 226, 0.15);
        border-left: 3px solid #8a2be2;
        border-top: 1px solid rgba(138, 43, 226, 0.3);
        border-right: 1px solid rgba(138, 43, 226, 0.3);
        border-bottom: 1px solid rgba(138, 43, 226, 0.3);
        box-shadow: 0 6px 15px rgba(138, 43, 226, 0.2);
        transform: translateX(4px);
    }
    
    [data-testid="stSidebar"] div.stButton > button[kind="primary"] {
        background: rgba(30, 30, 40, 0.5) !important;
        border: 1px solid rgba(255, 65, 108, 0.3) !important;
        color: #f8f8f2 !important;
    }
    
    [data-testid="stSidebar"] div.stButton > button[kind="primary"]:hover {
        background: linear-gradient(45deg, #ff416c, #ff4b2b) !important;
        border-color: transparent !important;
        box-shadow: 0 4px 15px rgba(255, 65, 108, 0.4) !important;
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
        color: #dcdcdc;
        transition: color 0.2s;
    }
    
    [data-testid="stSidebar"] div.stButton > button:hover p {
        color: #ffffff;
    }
    
    /* Sidebar Checkbox Styling */
    [data-testid="stSidebar"] .stCheckbox {
        background: rgba(30, 30, 42, 0.4);
        border: 1px solid rgba(255, 255, 255, 0.05);
        border-left: 3px solid transparent;
        border-radius: 8px;
        padding: 10px 14px;
        margin-bottom: 6px;
        transition: all 0.2s;
    }
    [data-testid="stSidebar"] .stCheckbox:hover {
        background: rgba(255, 65, 108, 0.1);
        border-left: 3px solid #ff416c;
        border-top: 1px solid rgba(255, 65, 108, 0.3);
        border-right: 1px solid rgba(255, 65, 108, 0.3);
        border-bottom: 1px solid rgba(255, 65, 108, 0.3);
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
    with open(HISTORY_FILE, "w") as f:
        json.dump(history, f, indent=2)

def get_relevant_matches(results: list[dict], score_margin: float = 0.35, min_matches: int = 1, max_matches: int = 5) -> list[dict]:
    """
    Return a dynamic subset of results scoring within `score_margin` of the top result,
    bounded between `min_matches` and `max_matches`.
    """
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

# Render the beautiful animated main title
st.markdown("<h1 class='main-title'>✨ Deja AI Mentor</h1>", unsafe_allow_html=True)

# Allow the user to navigate and manage their past problem-solving sessions
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
    
    # Display the 15 most recent sessions as quick-access buttons
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

    # Tuck older sessions neatly into an expandable section to save space
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
    # Check if we're resuming a session, otherwise start a fresh one in the history log
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


# Determine which screen to render based on the user's current progress stage
if st.session_state.stage == "welcome":
    html_content = """
    <style>
    @keyframes float {
        0% { transform: translateY(0px); }
        50% { transform: translateY(-10px); }
        100% { transform: translateY(0px); }
    }
    @keyframes glowText {
        0% { text-shadow: 0 0 10px rgba(138, 43, 226, 0.3), 0 0 20px rgba(138, 43, 226, 0.3); }
        50% { text-shadow: 0 0 20px rgba(138, 43, 226, 0.8), 0 0 30px rgba(138, 43, 226, 0.6); }
        100% { text-shadow: 0 0 10px rgba(138, 43, 226, 0.3), 0 0 20px rgba(138, 43, 226, 0.3); }
    }
    .welcome-container-pro {
        text-align: center;
        padding: 60px 50px;
        background: linear-gradient(145deg, rgba(20,20,30,0.8) 0%, rgba(10,10,15,0.9) 100%);
        backdrop-filter: blur(30px);
        -webkit-backdrop-filter: blur(30px);
        border: 1px solid rgba(138, 43, 226, 0.3);
        border-radius: 30px;
        box-shadow: 
            0 20px 50px rgba(0, 0, 0, 0.6),
            inset 0 0 0 1px rgba(255, 255, 255, 0.05),
            0 0 40px rgba(138, 43, 226, 0.15);
        animation: float 6s ease-in-out infinite;
        margin-top: 30px;
        margin-bottom: 20px;
    }
    .welcome-title {
        background: linear-gradient(-45deg, #fff, #e0e0e0, #fff);
        -webkit-background-clip: text;
        -webkit-text-fill-color: transparent;
        font-weight: 800;
        font-size: 3rem;
        margin-bottom: 25px;
        letter-spacing: -1px;
        animation: glowText 4s infinite alternate;
    }
    .welcome-text {
        color: #b0b0b0;
        font-size: 1.25rem;
        line-height: 1.8;
        font-weight: 400;
        max-width: 800px;
        margin: 0 auto;
    }
    .highlight-badge {
        background: linear-gradient(90deg, #8a2be2, #4facfe);
        color: white;
        padding: 3px 12px;
        border-radius: 20px;
        font-weight: 600;
        font-size: 1.1rem;
        box-shadow: 0 4px 15px rgba(138, 43, 226, 0.4);
        display: inline-block;
        margin: 0 4px;
    }
    </style>
    <div class='welcome-container-pro'>
        <h2 class='welcome-title'>Welcome to Deja! ✨</h2>
        <p class='welcome-text'>
            Your personalized AI competitive programming mentor.<br><br>
            I analyze your past successful code submissions and help guide you through new, unfamiliar problems using <span class="highlight-badge">only</span> the techniques and algorithmic intuitions you've already mastered.
        </p>
    </div>
    """
    st.markdown(html_content, unsafe_allow_html=True)
    
    col1, col2, col3 = st.columns([1, 1, 1])
    with col2:
        if st.button("🚀 Start Learning Now", type="primary", use_container_width=True):
            st.session_state.stage = "input"
            st.session_state.problem_statement = ""
            st.session_state.results = None
            st.session_state.session_id = str(uuid.uuid4())
            st.session_state.is_history_view = False
            st.rerun()


elif st.session_state.stage == "input":
    with st.container():
        st.markdown("<div class='input-header'><span class='input-header-icon'>🧩</span><span class='input-header-text'>What problem are we tackling today?</span></div>", unsafe_allow_html=True)
        problem_input = st.text_area("Paste the problem statement here:", height=250, key="prob_input", placeholder="e.g. Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target...")
        
        st.markdown("<br>", unsafe_allow_html=True)
        col1, col2, col3 = st.columns([1, 2, 1])
        with col2:
            if st.button("🧠 Analyze Problem", use_container_width=True):
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

# Render the core problem-solving flow, dynamically unlocking deeper hints
if st.session_state.stage in ["hint", "pseudocode", "code", "solved", "ingesting"]:
    
    # Keep the original problem clearly visible at the top of the screen
    with st.container():
        st.markdown("<div class='section-header'><span class='section-header-icon'>📄</span><span class='section-header-text'>Problem Statement</span></div>", unsafe_allow_html=True)
        st.info(st.session_state.problem_statement)
    
    # Stage 1: Give the user a gentle nudge towards the right algorithmic pattern
    with st.container():
        if st.session_state.is_confident:
            st.markdown("<div class='section-header'><span class='section-header-icon'>💡</span><span class='section-header-text'>Stage 1: Hint</span></div>", unsafe_allow_html=True)
            if st.session_state.results:
                past_problems_md = ""
                relevant_matches = get_relevant_matches(st.session_state.results)
                for res in relevant_matches:
                    title = res.get('title', res.get('title_slug', 'Unknown Problem'))
                    diff = res.get('difficulty', 'Unknown')
                    tech = res.get('core_technique', '')
                    tech_str = f" - *{tech}*" if tech else ""
                    past_problems_md += f"- **{title}** ({diff}){tech_str}\n"
                with st.expander("📚 Based on your past solved problems", expanded=False):
                    st.info(past_problems_md)
                
            st.info(st.session_state.hint)
        else:
            st.markdown("##### ❌ No confident match found.")
            st.markdown("I found a few somewhat related problems, but none closely matches this one.")
            if st.session_state.results:
                past_problems_md = ""
                relevant_matches = get_relevant_matches(st.session_state.results)
                for res in relevant_matches:
                    title = res.get('title', res.get('title_slug', 'Unknown Problem'))
                    diff = res.get('difficulty', 'Unknown')
                    tech = res.get('core_technique', '')
                    tech_str = f" - *{tech}*" if tech else ""
                    past_problems_md += f"- **{title}** ({diff}){tech_str}\n"
                st.info(past_problems_md)
            
            if not st.session_state.coach_mode_enabled:
                if not st.session_state.stay_independent:
                    st.markdown("Would you like me to act as your reasoning coach?")
                    col_c1, col_c2 = st.columns(2)
                    with col_c1:
                        if st.button("Stay Independent", use_container_width=True):
                            st.session_state.stay_independent = True
                            st.rerun()
                    with col_c2:
                        if st.button("Enable Coach Mode", type="primary", use_container_width=True):
                            st.session_state.coach_mode_enabled = True
                            st.rerun()
                else:
                    st.info('_"A smooth sea never made a skilled sailor. Trust your instincts and conquer this problem on your own!"_ 🌊')
                    
                    if st.session_state.stage == "hint":
                        col_ind1, col_ind2 = st.columns(2)
                        with col_ind1:
                            if st.button("✅ Solved?", use_container_width=True):
                                with st.spinner("Generating optimal reference code for comparison..."):
                                    if not st.session_state.code:
                                        st.session_state.code = generate_hint(st.session_state.problem_statement, st.session_state.results, stage="code")
                                st.session_state.stage = "solved"
                                update_history()
                                st.rerun()
                        with col_ind2:
                            if st.button("Enable Coach Mode", use_container_width=True):
                                st.session_state.coach_mode_enabled = True
                                st.session_state.stay_independent = False
                                st.rerun()
            else:
                st.markdown("<div class='section-header'><span class='section-header-icon'>💡</span><span class='section-header-text'>Stage 1: Hint</span></div>", unsafe_allow_html=True)
                if st.session_state.coach_data is None:
                    with st.spinner("Generating coaching guidance..."):
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
            col1, col2 = st.columns(2)
            with col1:
                if st.button("✅ Yes, I solved it!"):
                    st.session_state.stage = "solved"
                    update_history()
                    st.rerun()
            with col2:
                if st.button("🤔 No, show pseudocode"):
                    with st.spinner("Analyzing optimal approach to generate pseudocode..."):
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

    # Stage 2: Break down the logic step-by-step without giving away the exact code
    if st.session_state.stage in ["pseudocode", "code", "solved", "ingesting"] and st.session_state.pseudocode:
        with st.container():
            st.markdown("<div class='section-header'><span class='section-header-icon'>🛠️</span><span class='section-header-text'>Stage 2: Pseudocode</span></div>", unsafe_allow_html=True)
            st.info(st.session_state.pseudocode)
            
            if st.session_state.stage == "pseudocode":
                st.markdown("---")
                st.markdown("#### Did this pseudocode help you solve it?")
                col1, col2 = st.columns(2)
                with col1:
                    if st.button("✅ Yes, I solved it!", key="solve_ps"):
                        st.session_state.stage = "solved"
                        update_history()
                        st.rerun()
                with col2:
                    if st.button("🆘 No, show full code"):
                        with st.spinner("Loading reference code..."):
                            if not st.session_state.code:
                                st.session_state.code = generate_hint(st.session_state.problem_statement, st.session_state.results, stage="code")
                            st.session_state.stage = "code"
                            update_history()
                            st.rerun()

    # Stage 3: Reveal the optimal reference implementation for study
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

    # Celebrate success and prompt the user to add their new knowledge to the database
    if st.session_state.stage == "solved":
        if not st.session_state.is_history_view:
            if not st.session_state.get("balloons_shown", False):
                st_fireworks()
                st.session_state.balloons_shown = True
            with st.container():
                st.markdown("### 🎉 Awesome job!")
                st.markdown("Would you like to ingest your new solution into the database so Deja can learn from it?")
                if st.button("📥 Yes, let's ingest it!"):
                    st.session_state.stage = "ingesting"
                    update_history()
                    st.rerun()
        else:
            with st.container():
                st.success("🎉 You successfully solved this problem in a previous session!")
            
    if st.session_state.stage == "ingesting":
        with st.container():
            st.markdown("### 📥 Ingest New Solution")
            
            title_slug = st.text_input("Problem Title Slug (e.g., 'two-sum'):")
            solution_code = st.text_area("Paste your accepted Python code here:", height=250)
            
            if st.button("🚀 Save & Ingest"):
                if not title_slug or not solution_code:
                    st.error("Please provide both a title slug and your solution code.")
                else:
                    with st.spinner("Analyzing and updating vectorstore (this takes ~5s)..."):
                        res = run_ingestion(st.session_state.problem_statement, title_slug, solution_code)
                        if res and res.get("status") == "success":
                            st.success("✅ Ingestion successful! Your solution is now searchable.")
                            # Send the user back to the home screen to tackle their next challenge
                            st.session_state.stage = "welcome"
                            update_history()
                        else:
                            st.error(f"❌ Ingestion failed: {res.get('message') if res else 'Unknown error'}")
