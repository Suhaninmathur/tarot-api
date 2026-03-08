# Tarot Card Reader API

A C++ REST API built with [Crow](https://crowcpp.org), deployable on Render via Docker.

---

## API Endpoints

### `GET /health`
Liveness check.
```json
{ "status": "ok", "service": "Tarot Card Reader API" }
```

### `GET /api/cards`
Returns all 10 available cards.
```json
{
  "cards": [
    { "id": 1, "name": "The Fool" },
    { "id": 2, "name": "The Magician" },
    ...
  ]
}
```

### `GET /api/moods`
Returns all 5 moods.
```json
{
  "moods": [
    { "id": 1, "name": "Happy" },
    { "id": 2, "name": "Sad" },
    ...
  ]
}
```

### `POST /api/reading`
Perform a tarot reading.

**Request:**
```json
{
  "name":    "Suhani",
  "mood":    "Excited",
  "past":    1,
  "present": 3,
  "future":  7
}
```

**Response:**
```json
{
  "name": "Suhani",
  "mood": "Excited",
  "cards": {
    "past":    { "id": 1, "name": "The Fool" },
    "present": { "id": 3, "name": "The High Priestess" },
    "future":  { "id": 7, "name": "The Chariot" }
  },
  "reading": {
    "past":       "I see the Fool sitting in your past...",
    "present":    "The High Priestess sits in your present...",
    "future":     "The Chariot charges through your future...",
    "synergy":    "Your energy is electric right now — ...",
    "suggestion": "Suggestion: Identify the one goal..."
  }
}
```

---

## Run Locally with Docker

```bash
docker build -t tarot-api .
docker run -p 8080:8080 tarot-api
```

Then call: `http://localhost:8080/api/reading`

---

## Run Locally without Docker

Requirements: `g++`, `cmake >= 3.16`, `libboost-all-dev`

```bash
cmake -B build
cmake --build build --target tarot_api
./build/tarot_api
```

---

## Deploy to Render

1. Push this repo to GitHub
2. Go to [render.com](https://render.com) → **New → Web Service**
3. Connect your GitHub repo
4. Set these options:

| Setting | Value |
|---|---|
| Environment | **Docker** |
| Branch | `main` |
| Port | `8080` |

5. Click **Deploy** — Render builds the Docker image automatically

Your API will be live at:
```
https://your-app-name.onrender.com/api/reading
```

---

## React Integration Example

```js
const response = await fetch('https://your-app.onrender.com/api/reading', {
  method: 'POST',
  headers: { 'Content-Type': 'application/json' },
  body: JSON.stringify({
    name:    'Suhani',
    mood:    'Excited',
    past:    1,
    present: 3,
    future:  7,
  }),
});
const data = await response.json();
console.log(data.reading.synergy);
```

---

## Project Structure

```
tarot_project/
├── api/
│   └── server.cpp          ← Crow REST API
├── models/
│   ├── Card.h / Card.cpp
│   ├── TarotCard.h
│   └── User.h
├── services/
│   ├── TarotDeck.h / .cpp
│   ├── TarotEngine.h
│   └── SynergyEngine.h
├── utils/
│   ├── TarotCombinations.h  ← 720 readings
│   ├── FileManager.h
│   └── DataLoader.h
├── main.cpp                 ← CLI app
├── Dockerfile
├── CMakeLists.txt
└── README.md
```
