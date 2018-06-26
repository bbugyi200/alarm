cmake_minimum_required(VERSION 2.8)
include(shared.cmake)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/gutils/src)
