//
// Created by Chris on 9/22/2020.
//

#ifndef FAKESQL_RUNNER_H
#define FAKESQL_RUNNER_H
#include "../StatmentParser/StatementParser.h"

class Runner {
public:
    static void runExpression(Expression* expression);
};


#endif //FAKESQL_RUNNER_H
