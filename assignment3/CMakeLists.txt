cmake_minimum_required(VERSION 3.21)

project(assignment3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(task2 task_2.cpp)
add_executable(task3 task_3/commodity.cpp)
add_executable(task4 task_4.cpp)
