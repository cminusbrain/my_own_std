cmake_minimum_required(VERSION 3.0)
project(my_own_std_file)

set(proj_headers file.h)
set(proj_sources file.cpp)

add_library(${PROJECT_NAME} STATIC ${proj_headers} ${proj_sources})
target_link_libraries(${PROJECT_NAME} vector)
