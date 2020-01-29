cmake_minimum_required(VERSION 3.11)
project(hello)

# Get Googletest

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        master
)

FetchContent_GetProperties(googletest)
if (NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif ()

# Get Boost

find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra -Wunused")

add_executable(hello  main.cpp)
add_executable(boost  boostArray.cpp)
add_executable(gtests gtestCheck.cpp)
target_link_libraries(gtests gtest_main gmock_main)
