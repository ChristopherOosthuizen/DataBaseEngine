cmake_minimum_required(VERSION 3.17)
project(FakeSql)

set(CMAKE_CXX_STANDARD 14)

add_executable(FakeSql main.cpp FakeSql/Model/bTree.cpp FakeSql/Model/bTree.h FakeSql/Model/BTreeAct.cpp FakeSql/Parser/Parser.cpp FakeSql/Parser/Parser.h)
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)