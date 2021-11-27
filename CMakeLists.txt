cmake_minimum_required(VERSION 3.17)

set(CPM_DOWNLOAD_VERSION 0.34.0)
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
    message(STATUS "Downloading CPM.cmake")
    file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif()

include(${CPM_DOWNLOAD_LOCATION})

project(ringmud)

CPMAddPackage(
        NAME ringnet
        GITHUB_REPOSITORY volundmush/ringnet
        GIT_TAG main
)

CPMAddPackage(
        NAME asio
        GITHUB_REPOSITORY chriskohlhoff/asio
        GIT_TAG asio-1-21-0
)

CPMAddPackage(
        NAME entt
        GITHUB_REPOSITORY skypjack/entt
        VERSION 3.8.1
)

CPMAddPackage(
        NAME json
        GITHUB_REPOSITORY nlohmann/json
        VERSION 3.10.4
)

CPMAddPackage(
        NAME fmt
        GITHUB_REPOSITORY fmtlib/fmt
        GIT_TAG 8.0.1
)


CPMAddPackage(
        NAME eff_random
        GITHUB_REPOSITORY effolkronium/random
        VERSION 1.4.0
)


include_directories(PUBLIC
        include/ringmud
        ${asio_SOURCE_DIR}/asio/include
        ${entt_SOURCE_DIR}/single_include
        ${json_SOURCE_DIR}/single_include
        ${fmt_SOURCE_DIR}/include
        ${eff_random_SOURCE_DIR}/include
        ${ringnet_SOURCE_DIR}/include
)

file(GLOB RINGMUD_INCLUDE include/*.h)
file(GLOB RINGMUD_SRC src/*.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-fpermissive")

add_library(ringmud ${RINGMUD_INCLUDE} ${RINGMUD_SRC})
link_libraries(ringmud)
