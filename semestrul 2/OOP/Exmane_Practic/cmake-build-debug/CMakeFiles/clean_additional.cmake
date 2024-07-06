# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Exmane_Practic_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Exmane_Practic_autogen.dir\\ParseCache.txt"
  "Exmane_Practic_autogen"
  )
endif()
