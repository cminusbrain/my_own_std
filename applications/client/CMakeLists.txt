cmake_minimum_required(VERSION 3.0)
project(client)

FILE(GLOB_RECURSE PROJECT_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_link_libraries(${PROJECT_NAME}
        -Wl,--start-group
            pthread
            socket
            transport
        -Wl,--end-group)