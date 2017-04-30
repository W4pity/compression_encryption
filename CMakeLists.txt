cmake_minimum_required(VERSION 2.8)
project(compress)
set(CMAKE_C_COMPILER "g++")
set(CMAKE_C_FLAGS "-Wall -Wextra -std=c++17 -Werror -g -pedantic")
set(CMAKE_C_FLAGS_RELEASE "-O2")

set(SRCC
    src/compressor/main.cc
    src/compressor/class/compressor.cc
)
set(SRCD
    src/decompressor/main.cc
    src/decompressor/class/decompressor.cc
)

add_executable(compress ${SRCC})
add_executable(decompress ${SRCD})
