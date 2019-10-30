cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)
project(solvant)

# include all of our source files
# when we move away from using .hpp files
# only we can generate libraries instead
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..) 
add_executable(solvant driver/main.cpp)

include(cmake/googletest.cmake)
fetch_googletest(
    ${PROJECT_SOURCE_DIR}/cmake
    ${PROJECT_BINARY_DIR}/googletest
    )

add_subdirectory(tests)
enable_testing()

