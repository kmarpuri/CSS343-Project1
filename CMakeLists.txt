cmake_minimum_required(VERSION 3.26.5)
project(CSS343_Project1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CSS343_Project1
        main.cpp
        MyVector.cpp
        MyVector.h)
