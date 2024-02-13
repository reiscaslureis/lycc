cmake_minimum_required(VERSION 3.17)
project(lycc)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    include
    include/scanner
)

add_executable(lycc 
    src/main.cpp
    src/scanner/tag.cpp
    src/scanner/token.cpp
    src/scanner/scanner.cpp
)