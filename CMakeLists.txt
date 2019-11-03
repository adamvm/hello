cmake_minimum_required(VERSION 3.9)
project(hello)

add_subdirectory(gtest)
include_directories(${gtest_SOURCE_DIR}/include
                    ${gtest_SOURCE_DIR})

find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")

add_executable(hello  main.cpp)
add_executable(boost  boostArray.cpp)
add_executable(gtests gtestCheck.cpp)
target_link_libraries(gtests gtest_main)
