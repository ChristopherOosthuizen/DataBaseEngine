set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES} Model/bTree.cpp Model/bTree.h Parser/Parser.cpp Parser/Parser.h Errors/Errors.cpp Errors/Errors.h  StatmentParser/StatementParser.cpp StatmentParser/StatementParser.h Model/Model.cpp Model/Model.h Model/DataObject.cpp Model/DataObject.h)

add_executable(${BINARY}_run ${SOURCES}  Model/bTree.cpp Model/bTree.h Parser/Parser.cpp Parser/Parser.h Errors/Errors.cpp Errors/Errors.h  StatmentParser/StatementParser.cpp StatmentParser/StatementParser.h Model/Model.cpp Model/Model.h Model/DataObject.cpp Model/DataObject.h)

add_library(${BINARY}_lib STATIC ${SOURCES} Model/bTree.cpp Model/bTree.h Parser/Parser.cpp Parser/Parser.h Errors/Errors.cpp Errors/Errors.h  StatmentParser/StatementParser.cpp StatmentParser/StatementParser.h Model/Model.cpp Model/Model.h Model/DataObject.cpp Model/DataObject.h StatmentRunner/Instance.cpp StatmentRunner/Instance.h)