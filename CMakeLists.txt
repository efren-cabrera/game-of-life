cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

project(GameOfLife VERSION 1.0.0 LANGUAGES CXX)

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(include)