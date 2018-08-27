cmake_minimum_required(VERSION 2.8.4)
project(DMOJ)

add_executable(output output/main.cpp)
add_executable(testrunner testrunner/main.cpp)
file(GLOB TASKS "tasks/*.cpp")
file(GLOB_RECURSE HEADERS "library/*.hpp")

set(CMAKE_CXX_STANDARD 14)

add_executable(test ${TASKS} ${HEADERS})
