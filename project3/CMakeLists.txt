cmake_minimum_required(VERSION 3.27)
project(project3)

set(CMAKE_CXX_STANDARD 17)

add_executable(project3 main.cpp
        node.cpp
        node.h)
