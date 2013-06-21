cmake_minimum_required (VERSION 2.6)
project (huffman)

set (CMAKE_CXX_FLAGS "-O2 -g")

add_library(huffman SHARED huffman.cpp)
add_executable(main main.cpp)

target_link_libraries(main huffman)