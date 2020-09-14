cmake_minimum_required(VERSION 3.0)
project(common)

add_library(${PROJECT_NAME} INTERFACE)
target_sources(${PROJECT_NAME} INTERFACE
                ${CMAKE_CURRENT_SOURCE_DIR}/helpers.h
                ${CMAKE_CURRENT_SOURCE_DIR}/non_copyable.h
)   