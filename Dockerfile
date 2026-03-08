FROM debian:bookworm-slim AS builder

RUN apt-get update && apt-get install -y \
    build-essential \
    wget \
    libssl-dev \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

RUN wget -q \
    "https://github.com/CrowCpp/Crow/releases/download/v1.0%2B5/crow_all.h" \
    -O /usr/local/include/crow_all.h

COPY . .

RUN g++ -std=c++17 -O2 \
    -I. -Imodels -Iservices -Iutils -Iapi \
    -I/usr/local/include \
    -DCROW_USE_BOOST=0 \
    api/server.cpp \
    models/Card.cpp \
    services/TarotDeck.cpp \
    -o tarot_api \
    -lpthread \
    -lssl -lcrypto \
    && echo "=== Build successful ==="

FROM debian:bookworm-slim AS runner

RUN apt-get update && apt-get install -y \
    libssl3 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY --from=builder /app/tarot_api ./tarot_api
RUN mkdir -p /app/data

ENV PORT=8080
EXPOSE 8080

CMD ["./tarot_api"]