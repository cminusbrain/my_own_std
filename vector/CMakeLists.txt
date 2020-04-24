cmake_minimum_required(VERSION 3.0)
project(my_own_std_vector)

set(proj_headers vector.h)
set(proj_sources vector.cpp)

add_library(vector STATIC ${proj_headers} ${proj_sources})