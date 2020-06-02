set(_tests
  thomas_test
)

foreach(_test IN LISTS _tests)
  add_executable(${_test} ${_test}.cpp)
  target_link_libraries(${_test} gtest_main)
  add_test(NAME ${_test} COMMAND ${_test})
endforeach()
