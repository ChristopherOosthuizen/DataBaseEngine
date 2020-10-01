set(BINARY ${CMAKE_PROJECT_NAME}_tst)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES} ../FakeSql/Model/bTree.cpp ../FakeSql/Model/bTree.h ../FakeSql/Parser/Parser.cpp ../FakeSql/Parser/Parser.h  ../FakeSql/StatmentParser/StatementParser.cpp ../FakeSql/StatmentParser/StatementParser.h ../FakeSql/Model/Model.cpp ../FakeSql/Model/Model.h ../FakeSql/Model/DataObject.cpp ../FakeSql/Model/DataObject.h main.cpp TokenizerTest.cpp StatmentParserTest.cpp ModelTest.cpp)

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
