# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "AlteMelodii_autogen"
  "CMakeFiles\\AlteMelodii_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\AlteMelodii_autogen.dir\\ParseCache.txt"
  )
endif()
