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

FetchContent_Declare(
        boost
        GIT_REPOSITORY https://github.com/boostorg/boost.git
        GIT_TAG        master
)
FetchContent_GetProperties(boost)
if (NOT boost_POPULATED)
    FetchContent_Populate(boost)
    add_subdirectory(${boost_SOURCE_DIR} ${boost_BINARY_DIR})
endif ()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")

add_executable(hello  main.cpp)
add_executable(boost  boostArray.cpp)
add_executable(gtests gtestCheck.cpp)
target_link_libraries(gtests gtest_main gmock_main)
