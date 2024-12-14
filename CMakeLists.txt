cmake_minimum_required(VERSION 3.24)
project(Matrix)
set(target_name "Matrix")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Matrix main.cpp
                      Matrix.cpp 
                      Matrix.h)