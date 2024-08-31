cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project("Task2")

SET(CMAKE_CXX_STANDARD 17)

SET(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES
    *.cpp
)


add_executable(task2 ${SOURCES})