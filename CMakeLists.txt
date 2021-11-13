cmake_minimum_required(VERSION 3.20)

project(ringmud)
include(FetchContent)

FetchContent_Declare(
        ASIO
        GIT_REPOSITORY https://github.com/chriskohlhoff/asio
        GIT_TAG master
)

FetchContent_Declare(
        entt
        GIT_REPOSITORY https://github.com/skypjack/entt
        GIT_TAG master
)

FetchContent_MakeAvailable(ASIO entt)

file(GLOB RINGMUD_INCLUDE include/*.h)
file(GLOB RINGMUD_SRC src/*.cpp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-fpermissive")

include_directories(include)
link_libraries(asio entt)

add_library(ringmud ${RINGMUD_INCLUDE} ${RINGMUD_SRC})
link_libraries(ringmud)

include_directories(PUBLIC ${asio_SOURCE_DIR}/asio/include ${entt_SOURCE_DIR}/single_include)
message(${entt_SOURCE_DIR})
