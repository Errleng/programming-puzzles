cmake_minimum_required(VERSION 2.8.12)

project(MonsterHunter)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core)

file(GLOB SOURCES *.h *.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} Qt5::Core)
