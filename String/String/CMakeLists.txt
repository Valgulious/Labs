cmake_minimum_required(VERSION 3.8)
project(String)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp String.cpp String.h StringIter.cpp StringIter.h)
add_executable(String ${SOURCE_FILES})