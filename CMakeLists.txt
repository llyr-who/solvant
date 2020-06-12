cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
project(solvant)

include_directories(solvant) 

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-Wall -mavx -mfma -Ofast")

enable_testing()

include(cmake/FetchContent_Googletest.cmake)
include(cmake/FetchContent_Googlebenchmark.cmake)

add_subdirectory(solvant)
add_subdirectory(examples)
add_subdirectory(docs)

