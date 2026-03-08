# ── Stage 1: Build ───────────────────────────────────────────────────────────
FROM debian:bookworm-slim AS builder

RUN apt-get update && apt-get install -y \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

# Zero external dependencies — pure stdlib + POSIX sockets
RUN g++ -std=c++17 -O2 \
    -I. -Imodels -Iservices -Iutils -Iapi \
    api/server.cpp \
    models/Card.cpp \
    services/TarotDeck.cpp \
    -o tarot_api \
    -lpthread \
    && echo "=== Build successful ==="

# ── Stage 2: Run ─────────────────────────────────────────────────────────────
FROM debian:bookworm-slim AS runner

WORKDIR /app
COPY --from=builder /app/tarot_api ./tarot_api
RUN mkdir -p /app/data

ENV PORT=8080
EXPOSE 8080

CMD ["./tarot_api"]
