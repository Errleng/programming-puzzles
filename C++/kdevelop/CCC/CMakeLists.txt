cmake_minimum_required(VERSION 2.6)
project(ccc)

add_executable(ccc main.cpp)

install(TARGETS ccc RUNTIME DESTINATION bin)
