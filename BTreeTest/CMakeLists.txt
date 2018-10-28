cmake_minimum_required(VERSION 3.8)
project(BTreeTest)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BTree.cpp BTree.h)
add_executable(BTreeTest ${SOURCE_FILES})