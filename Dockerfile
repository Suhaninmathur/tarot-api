FROM debian:bookworm-slim AS builder

RUN apt-get update && apt-get install -y \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .

RUN g++ -std=c++17 -O2 \
    -I. -Imodels -Iservices -Iutils -Iapi \
    api/server.cpp \
    models/Card.cpp \
    services/TarotDeck.cpp \
    utils/TarotCombinations.cpp \
    -o tarot_api \
    -lpthread

FROM debian:bookworm-slim AS runner

WORKDIR /app
COPY --from=builder /app/tarot_api ./tarot_api
RUN mkdir -p /app/data

ENV PORT=8080
EXPOSE 8080

CMD ["./tarot_api"]
