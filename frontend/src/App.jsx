import { useState } from "react";

// ── Change this to your Render URL after deploying ────────────────────────────
const API_BASE = import.meta.env.VITE_API_URL || "http://localhost:8080";

const MOODS = ["Happy", "Sad", "Neutral", "Confused", "Excited"];
const MOOD_EMOJI = { Happy: "😊", Sad: "😔", Neutral: "😐", Confused: "😕", Excited: "🤩" };

const CARDS = [
  { id: 1,  name: "The Fool" },
  { id: 2,  name: "The Magician" },
  { id: 3,  name: "The High Priestess" },
  { id: 4,  name: "The Empress" },
  { id: 5,  name: "The Emperor" },
  { id: 6,  name: "The Lovers" },
  { id: 7,  name: "The Chariot" },
  { id: 8,  name: "Strength" },
  { id: 9,  name: "The Hermit" },
  { id: 10, name: "The Star" },
];

// ── Card face-down component ──────────────────────────────────────────────────
function CardSlot({ label, selected, onSelect, disabled, taken }) {
  return (
    <div style={{ textAlign: "center", flex: 1 }}>
      <p style={{ color: "#c9a96e", marginBottom: 8, fontSize: 13, letterSpacing: 2, textTransform: "uppercase" }}>
        {label}
      </p>
      <div style={{
        display: "grid", gridTemplateColumns: "repeat(5, 1fr)", gap: 6,
        background: "#1a1025", borderRadius: 10, padding: 10,
        border: "1px solid #3d2d5e"
      }}>
        {CARDS.map(c => {
          const isTaken = taken.includes(c.id) && c.id !== selected;
          const isSelected = selected === c.id;
          return (
            <button
              key={c.id}
              onClick={() => !isTaken && !disabled && onSelect(c.id)}
              title={isSelected ? c.name : ""}
              style={{
                width: "100%", aspectRatio: "1", borderRadius: 6,
                border: isSelected ? "2px solid #c9a96e" : "1px solid #3d2d5e",
                background: isSelected ? "#3d2057"
                  : isTaken ? "#111" : "#2a1842",
                color: isSelected ? "#c9a96e" : isTaken ? "#333" : "#7a5fa0",
                cursor: isTaken || disabled ? "not-allowed" : "pointer",
                fontSize: 14, fontWeight: "bold",
                transition: "all 0.2s",
              }}
            >
              {isSelected ? "✦" : isTaken ? "·" : c.id}
            </button>
          );
        })}
      </div>
      {selected && (
        <p style={{ color: "#e8d5b7", marginTop: 8, fontSize: 13, fontStyle: "italic" }}>
          ✦ {CARDS.find(c => c.id === selected)?.name}
        </p>
      )}
    </div>
  );
}

// ── Reading display ───────────────────────────────────────────────────────────
function ReadingDisplay({ data }) {
  const { cards, reading, mood, name } = data;

  const Section = ({ emoji, title, text, accent }) => (
    <div style={{
      background: "#1a1025", borderRadius: 10, padding: "18px 20px",
      borderLeft: `3px solid ${accent || "#7a5fa0"}`, marginBottom: 14
    }}>
      <p style={{ color: accent || "#c9a96e", fontSize: 12, letterSpacing: 2, marginBottom: 6, textTransform: "uppercase" }}>
        {emoji} {title}
      </p>
      <p style={{ color: "#e8d5b7", lineHeight: 1.7, fontSize: 15 }}>{text}</p>
    </div>
  );

  return (
    <div style={{ animation: "fadeIn 0.6s ease" }}>
      <div style={{
        textAlign: "center", marginBottom: 24,
        background: "linear-gradient(135deg, #2a1842, #1a1025)",
        borderRadius: 12, padding: "16px 20px",
        border: "1px solid #3d2d5e"
      }}>
        <p style={{ color: "#c9a96e", fontSize: 12, letterSpacing: 3, textTransform: "uppercase" }}>
          Reading for {name} · {mood}
        </p>
        <div style={{ display: "flex", justifyContent: "center", gap: 24, marginTop: 12 }}>
          {["past", "present", "future"].map(pos => (
            <div key={pos} style={{ textAlign: "center" }}>
              <p style={{ color: "#7a5fa0", fontSize: 11, letterSpacing: 2, textTransform: "uppercase" }}>{pos}</p>
              <p style={{ color: "#e8d5b7", fontSize: 14, marginTop: 4 }}>{cards[pos].name}</p>
            </div>
          ))}
        </div>
      </div>

      <Section emoji="🌒" title="Your Past"    text={reading.past}       accent="#7a5fa0" />
      <Section emoji="✦"  title="Your Present" text={reading.present}    accent="#9b59b6" />
      <Section emoji="★"  title="Your Future"  text={reading.future}     accent="#c9a96e" />

      <div style={{
        background: "linear-gradient(135deg, #2a1842, #1a1025)",
        borderRadius: 10, padding: "20px", marginBottom: 14,
        border: "1px solid #c9a96e33"
      }}>
        <p style={{ color: "#c9a96e", fontSize: 12, letterSpacing: 2, marginBottom: 8, textTransform: "uppercase" }}>
          🌟 The Reader's Interpretation
        </p>
        <p style={{ color: "#e8d5b7", lineHeight: 1.8, fontSize: 15, fontStyle: "italic" }}>
          {reading.synergy}
        </p>
      </div>

      <div style={{
        background: "#1a1025", borderRadius: 10, padding: "18px 20px",
        border: "1px dashed #3d2d5e"
      }}>
        <p style={{ color: "#9b59b6", fontSize: 12, letterSpacing: 2, marginBottom: 8, textTransform: "uppercase" }}>
          💡 Guidance for You
        </p>
        <p style={{ color: "#c9a96e", lineHeight: 1.7, fontSize: 14 }}>
          {reading.suggestion}
        </p>
      </div>
    </div>
  );
}

// ── Main App ──────────────────────────────────────────────────────────────────
export default function App() {
  const [step, setStep]         = useState("form");   // form | loading | result
  const [name, setName]         = useState("");
  const [mood, setMood]         = useState("");
  const [past, setPast]         = useState(null);
  const [present, setPresent]   = useState(null);
  const [future, setFuture]     = useState(null);
  const [result, setResult]     = useState(null);
  const [error, setError]       = useState("");

  const takenCards = [past, present, future].filter(Boolean);

  const canSubmit = name.trim() && mood && past && present && future;

  const handleSubmit = async () => {
    setError("");
    setStep("loading");
    try {
      const res = await fetch(`${API_BASE}/api/reading`, {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ name: name.trim(), mood, past, present, future }),
      });
      if (!res.ok) {
        const err = await res.json();
        throw new Error(err.error || "Server error");
      }
      const data = await res.json();
      setResult(data);
      setStep("result");
    } catch (e) {
      setError(e.message || "Could not reach the API. Is the server running?");
      setStep("form");
    }
  };

  const reset = () => {
    setStep("form"); setResult(null); setError("");
    setPast(null); setPresent(null); setFuture(null);
    setMood(""); setName("");
  };

  // ── Styles ──────────────────────────────────────────────────────────────────
  const inputStyle = {
    width: "100%", padding: "10px 14px", borderRadius: 8,
    border: "1px solid #3d2d5e", background: "#1a1025",
    color: "#e8d5b7", fontSize: 15, outline: "none",
    boxSizing: "border-box"
  };

  return (
    <div style={{
      minHeight: "100vh",
      background: "linear-gradient(160deg, #0d0818 0%, #1a0d2e 50%, #0d1a2e 100%)",
      fontFamily: "'Georgia', serif", color: "#e8d5b7",
      padding: "20px 16px"
    }}>
      <style>{`
        @keyframes fadeIn { from { opacity: 0; transform: translateY(16px); } to { opacity: 1; transform: none; } }
        @keyframes spin { to { transform: rotate(360deg); } }
        button:hover:not(:disabled) { opacity: 0.85; }
        input::placeholder { color: #4a3a6e; }
      `}</style>

      <div style={{ maxWidth: 680, margin: "0 auto" }}>

        {/* Header */}
        <div style={{ textAlign: "center", marginBottom: 32 }}>
          <p style={{ color: "#7a5fa0", letterSpacing: 6, fontSize: 11, textTransform: "uppercase", marginBottom: 6 }}>
            ✦ ✦ ✦
          </p>
          <h1 style={{ fontSize: 28, color: "#c9a96e", margin: 0, letterSpacing: 3 }}>
            TAROT CARD READER
          </h1>
          <p style={{ color: "#7a5fa0", fontSize: 13, marginTop: 6, letterSpacing: 1 }}>
            Unveil the past · Illuminate the present · Navigate the future
          </p>
        </div>

        {/* Error */}
        {error && (
          <div style={{
            background: "#2d0a0a", border: "1px solid #8b0000", borderRadius: 8,
            padding: "12px 16px", marginBottom: 20, color: "#ff6b6b", fontSize: 14
          }}>
            ⚠ {error}
          </div>
        )}

        {/* Loading */}
        {step === "loading" && (
          <div style={{ textAlign: "center", padding: "60px 0", animation: "fadeIn 0.4s ease" }}>
            <div style={{
              width: 48, height: 48, border: "3px solid #3d2d5e",
              borderTop: "3px solid #c9a96e", borderRadius: "50%",
              animation: "spin 1s linear infinite", margin: "0 auto 20px"
            }} />
            <p style={{ color: "#7a5fa0", letterSpacing: 2 }}>The cards are being read...</p>
          </div>
        )}

        {/* Result */}
        {step === "result" && result && (
          <div style={{ animation: "fadeIn 0.5s ease" }}>
            <ReadingDisplay data={result} />
            <button
              onClick={reset}
              style={{
                marginTop: 24, width: "100%", padding: "14px",
                borderRadius: 8, border: "1px solid #c9a96e",
                background: "transparent", color: "#c9a96e",
                fontSize: 14, letterSpacing: 2, cursor: "pointer",
                textTransform: "uppercase"
              }}
            >
              ✦ New Reading
            </button>
          </div>
        )}

        {/* Form */}
        {step === "form" && (
          <div style={{ animation: "fadeIn 0.4s ease" }}>

            {/* Name */}
            <div style={{ marginBottom: 20 }}>
              <label style={{ display: "block", color: "#c9a96e", fontSize: 12, letterSpacing: 2, textTransform: "uppercase", marginBottom: 8 }}>
                Your Name
              </label>
              <input
                style={inputStyle}
                placeholder="Enter your name..."
                value={name}
                onChange={e => setName(e.target.value)}
              />
            </div>

            {/* Mood */}
            <div style={{ marginBottom: 24 }}>
              <label style={{ display: "block", color: "#c9a96e", fontSize: 12, letterSpacing: 2, textTransform: "uppercase", marginBottom: 8 }}>
                How are you feeling today?
              </label>
              <div style={{ display: "flex", gap: 8, flexWrap: "wrap" }}>
                {MOODS.map(m => (
                  <button
                    key={m}
                    onClick={() => setMood(m)}
                    style={{
                      flex: 1, minWidth: 90, padding: "10px 8px", borderRadius: 8,
                      border: mood === m ? "1px solid #c9a96e" : "1px solid #3d2d5e",
                      background: mood === m ? "#2a1842" : "#1a1025",
                      color: mood === m ? "#c9a96e" : "#7a5fa0",
                      cursor: "pointer", fontSize: 13,
                    }}
                  >
                    {MOOD_EMOJI[m]} {m}
                  </button>
                ))}
              </div>
            </div>

            {/* Card pickers */}
            <div style={{ marginBottom: 24 }}>
              <label style={{ display: "block", color: "#c9a96e", fontSize: 12, letterSpacing: 2, textTransform: "uppercase", marginBottom: 12 }}>
                Choose Your Three Cards
              </label>
              <p style={{ color: "#7a5fa0", fontSize: 13, marginBottom: 16, lineHeight: 1.6 }}>
                The cards lie face down. Choose a number for each position — the card will be revealed in your reading.
              </p>
              <div style={{ display: "flex", flexDirection: "column", gap: 20 }}>
                <CardSlot label="Past"    selected={past}    onSelect={setPast}    taken={[present, future].filter(Boolean)} />
                <CardSlot label="Present" selected={present} onSelect={setPresent} taken={[past, future].filter(Boolean)} />
                <CardSlot label="Future"  selected={future}  onSelect={setFuture}  taken={[past, present].filter(Boolean)} />
              </div>
            </div>

            {/* Submit */}
            <button
              onClick={handleSubmit}
              disabled={!canSubmit}
              style={{
                width: "100%", padding: "16px",
                borderRadius: 8, border: "none",
                background: canSubmit
                  ? "linear-gradient(135deg, #6b3fa0, #9b59b6)"
                  : "#1a1025",
                color: canSubmit ? "#fff" : "#3d2d5e",
                fontSize: 15, letterSpacing: 3, cursor: canSubmit ? "pointer" : "not-allowed",
                textTransform: "uppercase", fontFamily: "Georgia, serif",
                transition: "all 0.3s"
              }}
            >
              ✦ Reveal My Reading ✦
            </button>
          </div>
        )}
      </div>
    </div>
  );
}
