cmake_minimum_required(VERSION 3.20)

project(ringmud)
include(FetchContent)

FetchContent_Declare(
        ASIO
        GIT_REPOSITORY https://github.com/chriskohlhoff/asio
        GIT_TAG master
)

FetchContent_Declare(
        sqlitepp
        GIT_REPOSITORY https://github.com/mpaland/sqlitepp
        GIT_TAG master
)

FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json
        GIT_TAG master
)

FetchContent_Declare(
        eff_random
        GIT_REPOSITORY https://github.com/effolkronium/random
        GIT_TAG master
)

FetchContent_Declare(
        entt
        GIT_REPOSITORY https://github.com/skypjack/entt
        GIT_TAG master
)

FetchContent_MakeAvailable(ASIO sqlitepp json eff_random entt)

file(GLOB RINGMUD_INCLUDE include/*.h)
file(GLOB RINGMUD_SRC src/*.cpp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_CXX_FLAGS "-fpermissive")

include_directories(include)
link_libraries(asio entt)

add_library(ringmud ${RINGMUD_INCLUDE} ${RINGMUD_SRC})
link_libraries(ringmud)

include_directories(PUBLIC ${asio_SOURCE_DIR}/asio/include ${entt_SOURCE_DIR}/single_include)
message(${entt_SOURCE_DIR})
add_executable(ring apps/ring.cpp)
