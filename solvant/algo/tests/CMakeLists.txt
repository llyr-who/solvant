add_executable(thomas_test thomas_test.cpp)
target_link_libraries(thomas_test
                      gtest_main
)

add_test(NAME thomas_test COMMAND thomas_test)
