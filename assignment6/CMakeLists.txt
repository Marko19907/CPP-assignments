cmake_minimum_required(VERSION 3.21)

project(assignment6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread -Wall -Wextra -Wno-unused-parameter")

add_executable(task_1 task_1.cpp)
add_executable(task_2 task_2.cpp)
