add_executable(matrix_test matrix_test.cpp)
target_link_libraries(matrix_test
                      gtest_main
)

add_executable(DOK_test DOK_test.cpp)
target_link_libraries(DOK_test
                      gtest_main
)

add_executable(tridiag_test tridiag_test.cpp)
target_link_libraries(tridiag_test
                      gtest_main
)

add_test(NAME matrix_test COMMAND matrix_test)
add_test(NAME DOK_test COMMAND DOK_test)
add_test(NAME tridiag_test COMMAND tridiag_test)
