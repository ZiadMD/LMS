cmake_minimum_required(VERSION 3.28)
project(LMS)

set(CMAKE_CXX_STANDARD 17)

add_executable(LMS main.cpp
        BookNode.cpp
        BookNode.h
        LibraryManagementSystem.cpp
        LibraryManagementSystem.h)
