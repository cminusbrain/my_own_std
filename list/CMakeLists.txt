cmake_minimum_required(VERSION 3.0)
project(my_own_std_list)

set(proj_headers list.h)
set(proj_sources list.cpp)

add_library(${PROJECT_NAME} STATIC ${proj_headers} ${proj_sources})
target_link_libraries(${PROJECT_NAME} vector)