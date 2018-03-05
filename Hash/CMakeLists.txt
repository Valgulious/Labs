cmake_minimum_required(VERSION 3.8)
project(Hash)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp HashTable.cpp HashTable.h)
add_executable(Hash ${SOURCE_FILES})