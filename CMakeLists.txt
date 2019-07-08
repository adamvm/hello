cmake_minimum_required(VERSION 3.13)
project(hello)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")

add_executable(hello main.cpp)

