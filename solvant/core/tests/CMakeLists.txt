set(_tests
matrix_test
vector_test
DOK_test
banded_test
)

foreach(_test IN LISTS _tests)
  add_executable(${_test} ${_test}.cpp)
  target_link_libraries(${_test} gtest_main)
  add_test(NAME ${_test} COMMAND ${_test})
endforeach()

