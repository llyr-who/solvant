find_package(Doxygen COMPONENTS dot)

if(NOT Doxygen_FOUND)
  message(STATUS "Doxygen or dot not found, unable to generate documentation.")
  return()
endif()

set(DOXYGEN_EXTRACT_ALL YES)

set(DOXYGEN_DOT_IMAGE_FORMAT svg)
set(DOXYGEN_INTERACTIVE_SVG  YES)

set(DOXYGEN_CALL_GRAPH   YES)
set(DOXYGEN_CALLEE_GRAPH YES)

set(DOXYGEN_HIDE_UNDOC_RELATIONS NO)

set(DOXYGEN_EXCLUDE_PATTERNS "*/tests/*")

doxygen_add_docs(docs
  base
  solver
  utils
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

