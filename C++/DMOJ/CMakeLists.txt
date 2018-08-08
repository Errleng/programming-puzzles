cmake_minimum_required(VERSION 3.12)
project(DMOJ)

set(CMAKE_CXX_STANDARD 14)

add_executable(ouput output/main.cpp)
add_executable(testrunner testrunner/main.cpp)

file(GLOB TASKS "tasks/*.cpp")
file(GLOB_RECURSE HEADERS "library/*.hpp" )

add_executable(test ${TASKS} ${HEADERS})