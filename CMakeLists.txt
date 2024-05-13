cmake_minimum_required(VERSION 3.26)
project(PointClass)

set(CMAKE_CXX_STANDARD 17)

add_executable(PointClass main.cpp
        Point.cpp
        Point.h
)
