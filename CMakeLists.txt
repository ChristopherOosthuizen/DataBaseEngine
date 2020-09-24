cmake_minimum_required(VERSION 3.17)
project(FakeSql)

set(CMAKE_CXX_STANDARD 14)

add_executable(FakeSql main.cpp FakeSql/Model/bTree.cpp FakeSql/Model/bTree.h FakeSql/Parser/Parser.cpp FakeSql/Parser/Parser.h FakeSql/Errors/Errors.cpp FakeSql/Errors/Errors.h  FakeSql/StatmentParser/StatementParser.cpp FakeSql/StatmentParser/StatementParser.h FakeSql/StatmentRunner/Runner.cpp FakeSql/StatmentRunner/Runner.cpp FakeSql/StatmentRunner/Runner.h FakeSql/Model/Model.cpp FakeSql/Model/Model.h FakeSql/Model/DataObject.cpp FakeSql/Model/DataObject.h)
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)