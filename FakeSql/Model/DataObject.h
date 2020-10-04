//
// Created by Chris on 9/23/2020.
//

#ifndef FAKESQL_DATAOBJECT_H
#define FAKESQL_DATAOBJECT_H

#include <string>
#include "../StatmentParser/StatementParser.h"
using namespace std;

class Literal{
public:
    TokenType m_type;
    Literal(Definition* definition);

    int m_key;
    string m_symbol;
};

class DataObject {
public:
    DataObject(Query* query);

    map<string,Literal*> m_definitions;
    string toString();
};



#endif //FAKESQL_DATAOBJECT_H
