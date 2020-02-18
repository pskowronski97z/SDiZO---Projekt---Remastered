cmake_minimum_required(VERSION 3.15)
project(E1)

set(CMAKE_CXX_STANDARD 20)

add_executable(E1 main.cpp cmake-build-debug/MyArray.cpp headers/MyArray.h)