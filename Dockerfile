# ── Stage 1: Build ───────────────────────────────────────────────────────────
FROM debian:bookworm-slim AS builder

RUN apt-get update && apt-get install -y \
    build-essential \
    wget \
    libboost-all-dev \
    libssl-dev \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Download Crow single-header directly (no git/cmake needed)
RUN wget -q \
    https://github.com/CrowCpp/Crow/releases/download/v1.0%2B5/crow_all.h \
    -O /usr/local/include/crow_all.h

# Copy all source files
COPY . .

# Compile API server with g++ directly — no CMake needed
RUN g++ -std=c++17 -O2 \
    -I. -Imodels -Iservices -Iutils -Iapi \
    -I/usr/local/include \
    api/server.cpp \
    models/Card.cpp \
    services/TarotDeck.cpp \
    -o tarot_api \
    -lpthread \
    -lboost_system \
    && echo "Build successful"

# ── Stage 2: Run ─────────────────────────────────────────────────────────────
FROM debian:bookworm-slim AS runner

RUN apt-get update && apt-get install -y \
    libboost-system1.81.0 \
    libssl3 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY --from=builder /app/tarot_api ./tarot_api
RUN mkdir -p /app/data

ENV PORT=8080
EXPOSE 8080

CMD ["./tarot_api"]