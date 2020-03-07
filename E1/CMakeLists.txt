cmake_minimum_required(VERSION 3.15)
project(E1)

set(CMAKE_CXX_STANDARD 20)

add_executable(E1 main.cpp cmake-build-debug/MyArray.cpp headers/MyArray.h cmake-build-debug/MyList.cpp headers/MyList.h cmake-build-debug/MyHeap.cpp headers/MyHeap.h cmake-build-debug/BSTTree.cpp headers/BSTTree.h cmake-build-debug/Menu.cpp headers/Menu.h)