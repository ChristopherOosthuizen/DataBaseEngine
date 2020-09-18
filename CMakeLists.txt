cmake_minimum_required(VERSION 3.17)
project(FakeSql)

set(CMAKE_CXX_STANDARD 14)

add_executable(FakeSql main.cpp FakeSql/bTree.cpp FakeSql/bTree.h)