cmake_minimum_required(VERSION 3.8)
project(Queue)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Queue.h)
add_executable(Queue ${SOURCE_FILES})