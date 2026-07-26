cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(bishop VERSION 0.1.0)

add_subdirectory(src)
add_subdirectory(examples)

# enable_testing()
# add_subdirectory(utests)
