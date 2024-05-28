# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\pregatiretest_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\pregatiretest_autogen.dir\\ParseCache.txt"
  "pregatiretest_autogen"
  )
endif()
