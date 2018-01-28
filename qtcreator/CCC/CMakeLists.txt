cmake_minimum_required(VERSION 2.8.12)

project(CCC)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS ON)

find_package(Qt5Core)

add_executable(${PROJECT_NAME} "main.cpp")
add_definitions(-std=c++11)

target_link_libraries(${PROJECT_NAME} Qt5::Core)
