cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(bishop VERSION 0.1.0)

enable_testing()

add_subdirectory(src)
add_subdirectory(utests)
