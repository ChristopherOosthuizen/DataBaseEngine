cmake_minimum_required(VERSION 3.16)
project(FakeSql)

set(CMAKE_CXX_STANDARD 14)
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

add_executable(FakeSql FakeSql/main.cpp FakeSql/Model/bTree.cpp FakeSql/Model/bTree.h FakeSql/Parser/Parser.cpp FakeSql/Parser/Parser.h FakeSql/Server/ServSock.cpp FakeSql/Server/ServSock.h  FakeSql/StatmentParser/StatementParser.cpp FakeSql/StatmentParser/StatementParser.h FakeSql/Model/Model.cpp FakeSql/Model/Model.h FakeSql/Model/DataObject.cpp FakeSql/Model/DataObject.h FakeSql/StatmentRunner/Instance.cpp FakeSql/StatmentRunner/Instance.h)
include_directories(FakeSql)

add_subdirectory(FakeSql)
add_subdirectory(lib/googletest)
add_subdirectory(tst)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")