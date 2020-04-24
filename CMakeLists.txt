cmake_minimum_required(VERSION 3.0)
project(my_own_std)

set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${PROJECT_DIR})

add_subdirectory(vector)
add_subdirectory(list)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} vector)