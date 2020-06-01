add_executable(matrix_test matrix_test.cpp)
target_link_libraries(matrix_test
                      gtest_main
)

add_executable(vector_test vector_test.cpp)
target_link_libraries(vector_test
                      gtest_main
)

add_executable(DOK_test DOK_test.cpp)
target_link_libraries(DOK_test
                      gtest_main
)

add_executable(banded_test banded_test.cpp)
target_link_libraries(banded_test
                      gtest_main
)


add_test(NAME matrix_test COMMAND matrix_test)
add_test(NAME vector_test COMMAND vector_test)
add_test(NAME DOK_test COMMAND DOK_test)
add_test(NAME banded_test COMMAND banded_test)
