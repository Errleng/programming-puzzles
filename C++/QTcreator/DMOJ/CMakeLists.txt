cmake_minimum_required(VERSION 2.8.12)

project(DMOJ)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

file(GLOB PROJ_SRC
    "*.h"
    "*.cpp"
)

add_executable(${PROJECT_NAME} ${PROJ_SRC})
