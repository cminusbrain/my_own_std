cmake_minimum_required(VERSION 3.0)
project(my_own_std)

#set( CMAKE_VERBOSE_MAKEFILE on )

set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${PROJECT_DIR})

add_subdirectory(common)
add_subdirectory(vector)
add_subdirectory(list)
add_subdirectory(file)
add_subdirectory(transport)
add_subdirectory(applications)