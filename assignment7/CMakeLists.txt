cmake_minimum_required(VERSION 3.21)

project(assignment7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(fraction task_1a/fraction.cpp)
add_executable(set set.cpp)
