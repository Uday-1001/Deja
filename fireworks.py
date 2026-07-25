# pyrefly: ignore [missing-import]
import streamlit.components.v1 as components

def st_fireworks():
    js = """
    <script>
    try {
        const doc = window.parent.document;
        // Only inject the fireworks engine once so we don't accidentally freeze the user's browser with duplicate scripts
        if (!doc.getElementById("canvas-confetti-script")) {
            let script = doc.createElement('script');
            script.id = "canvas-confetti-script";
            script.src = "https://cdn.jsdelivr.net/npm/canvas-confetti@1.9.3/dist/confetti.browser.min.js";
            script.onload = launchFireworks;
            doc.head.appendChild(script);
        } else {
            launchFireworks();
        }

        function launchFireworks() {
            var duration = 3 * 1000;
            var animationEnd = Date.now() + duration;
            var defaults = { startVelocity: 30, spread: 360, ticks: 60, zIndex: 9999999 };
            function randomInRange(min, max) { return Math.random() * (max - min) + min; }
            var interval = setInterval(function() {
                var timeLeft = animationEnd - Date.now();
                if (timeLeft <= 0) { return clearInterval(interval); }
                var particleCount = 50 * (timeLeft / duration);
                window.parent.confetti(Object.assign({}, defaults, { particleCount,
                    origin: { x: randomInRange(0.1, 0.3), y: Math.random() - 0.2 }
                }));
                window.parent.confetti(Object.assign({}, defaults, { particleCount,
                    origin: { x: randomInRange(0.7, 0.9), y: Math.random() - 0.2 }
                }));
            }, 250);
        }
    } catch (e) {
        console.error(e);
    }
    </script>
    """
    components.html(js, height=0, width=0)
