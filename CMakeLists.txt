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

find_package(Boost COMPONENTS program_options thread REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_definitions(-Wno-unused-variable)
add_definitions(-Wno-unused-parameter)
add_definitions(-Wall -Werror -pedantic -Wextra)

add_executable(hello  main.cpp)

add_executable(boost boostCheck.cpp)
target_link_libraries(boost ${Boost_LIBRARIES})

add_executable(gtests gtestCheck.cpp)
target_link_libraries(gtests gtest_main gmock_main)
