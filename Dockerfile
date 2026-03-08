# ── Stage 1: Build ───────────────────────────────────────────────────────────
FROM debian:bookworm-slim AS builder

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    libssl-dev \
    libboost-all-dev \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Copy all source files
COPY . .

# Build only the API server target
RUN cmake -B build \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_CXX_FLAGS="-O2" \
    && cmake --build build --target tarot_api --parallel $(nproc)

# ── Stage 2: Run ─────────────────────────────────────────────────────────────
FROM debian:bookworm-slim AS runner

RUN apt-get update && apt-get install -y \
    libboost-system1.81.0 \
    libssl3 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Copy just the compiled binary
COPY --from=builder /app/build/tarot_api ./tarot_api

# Create data directory for history
RUN mkdir -p /app/data

# Render sets PORT automatically; default 8080 for local Docker
ENV PORT=8080
EXPOSE 8080

CMD ["./tarot_api"]
