cmake_minimum_required(VERSION 3.16)
project(TarotReader CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ── Download Crow (header-only) ───────────────────────────────────────────────
include(FetchContent)
FetchContent_Declare(
    crow
    GIT_REPOSITORY https://github.com/CrowCpp/Crow.git
    GIT_TAG        v1.0+5
)
FetchContent_MakeAvailable(crow)

find_package(Threads REQUIRED)

# ── Include paths ─────────────────────────────────────────────────────────────
include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/models
    ${CMAKE_SOURCE_DIR}/services
    ${CMAKE_SOURCE_DIR}/utils
    ${CMAKE_SOURCE_DIR}/api
)

# ── Shared sources ────────────────────────────────────────────────────────────
set(SHARED_SOURCES
    models/Card.cpp
    services/TarotDeck.cpp
)

# ── CLI target ────────────────────────────────────────────────────────────────
add_executable(tarot
    main.cpp
    ${SHARED_SOURCES}
)

# ── API server target ─────────────────────────────────────────────────────────
add_executable(tarot_api
    api/server.cpp
    ${SHARED_SOURCES}
)
target_link_libraries(tarot_api PRIVATE Crow::Crow Threads::Threads)

# Create data/ dir
add_custom_command(TARGET tarot_api POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:tarot_api>/data
)
