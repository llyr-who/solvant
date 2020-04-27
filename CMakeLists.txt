cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
project(solvant)

include_directories(solvant) 

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-Wall -mavx -mfma -Ofast")

include(cmake/googletest.cmake)
fetch_googletest(
    ${PROJECT_SOURCE_DIR}/cmake
    ${PROJECT_BINARY_DIR}/googletest
    )

add_subdirectory(solvant)
add_subdirectory(docs)

