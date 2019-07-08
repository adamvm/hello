cmake_minimum_required(VERSION 3.13)
project(hello)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")

FIND_PACKAGE(Boost COMPONENTS program_options REQUIRED)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

add_executable(hello main.cpp)
add_executable(boost boostArray.cpp)

