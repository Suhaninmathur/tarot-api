FROM alpine:3.19 AS builder

RUN apk add --no-cache \
    g++ \
    make \
    wget \
    openssl-dev \
    boost-dev \
    linux-headers

WORKDIR /app

# Download Crow single header
RUN wget -q \
    "https://github.com/CrowCpp/Crow/releases/download/v1.0%2B5/crow_all.h" \
    -O /usr/local/include/crow_all.h

COPY . .

# Compile with verbose output so we can see any errors
RUN g++ -std=c++17 -O2 \
    -I. -Imodels -Iservices -Iutils -Iapi \
    -I/usr/local/include \
    api/server.cpp \
    models/Card.cpp \
    services/TarotDeck.cpp \
    -o tarot_api \
    -lpthread \
    -lssl -lcrypto \
    -lboost_system \
    && echo "BUILD OK"

FROM alpine:3.19 AS runner

RUN apk add --no-cache \
    libstdc++ \
    openssl \
    boost

WORKDIR /app
COPY --from=builder /app/tarot_api ./tarot_api
RUN mkdir -p /app/data

ENV PORT=8080
EXPOSE 8080

CMD ["./tarot_api"]