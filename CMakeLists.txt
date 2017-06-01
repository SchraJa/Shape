cmake_minimum_required(VERSION 3.7)
project(shape)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Circle.cpp Rectangle.cpp Triangle.cpp)
add_executable(shape ${SOURCE_FILES})