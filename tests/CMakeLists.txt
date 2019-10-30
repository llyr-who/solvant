add_executable(matrix_test matrix_test.cpp)
target_link_libraries(matrix_test
                      gtest_main
)

add_test(NAME matrix_test COMMAND matrix_test)
