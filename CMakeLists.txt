cmake_minimum_required(VERSION 3.17)
project(lycc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

include_directories(include)
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(lycc ${SOURCES})