cmake_minimum_required(VERSION 3.17)
project(FakeSql)

set(CMAKE_CXX_STANDARD 14)

add_executable(FakeSql main.cpp FakeSql/Model/bTree.cpp FakeSql/Model/bTree.h FakeSql/Model/BTreeAct.cpp FakeSql/Model/BTreeAct.h FakeSql/Model/Model.cpp FakeSql/Model/Model.h FakeSql/Model/DataSlot.cpp FakeSql/Model/DataSlot.cpp FakeSql/Model/DataSlot.h)
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)