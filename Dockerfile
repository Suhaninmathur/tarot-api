FROM debian:bookworm-slim AS builder

RUN apt-get update && apt-get install -y \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .

RUN g++ -std=c++17 -O2 -I. -Imodels -Iservices -Iutils -Iapi -c models/Card.cpp -o /tmp/Card.o
RUN g++ -std=c++17 -O2 -I. -Imodels -Iservices -Iutils -Iapi -c services/TarotDeck.cpp -o /tmp/TarotDeck.o
RUN g++ -std=c++17 -O2 -I. -Imodels -Iservices -Iutils -Iapi -c utils/TarotCombinations.cpp -o /tmp/TarotCombinations.o
RUN g++ -std=c++17 -O2 -I. -Imodels -Iservices -Iutils -Iapi -c api/server.cpp -o /tmp/server.o
RUN g++ /tmp/Card.o /tmp/TarotDeck.o /tmp/TarotCombinations.o /tmp/server.o -o tarot_api -lpthread

FROM debian:bookworm-slim AS runner

WORKDIR /app
COPY --from=builder /app/tarot_api ./tarot_api
RUN mkdir -p /app/data

ENV PORT=8080
EXPOSE 8080

CMD ["./tarot_api"]