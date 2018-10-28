cmake_minimum_required(VERSION 2.8.4)
project(DMOJ)

add_executable(output output/main.cpp)
add_executable(testrunner testrunner/main.cpp)
file(GLOB TASKS "tasks/*.cpp")
file(GLOB_RECURSE HEADERS "library/*.hpp")

set(CMAKE_CXX_STANDARD 14)
MATH(EXPR stack_size "16 * 1024 * 1024") # 8 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

add_executable(test ${TASKS} ${HEADERS})
