//
// Created by Chris on 9/23/2020.
//

#ifndef FAKESQL_DATAOBJECT_H
#define FAKESQL_DATAOBJECT_H

#include <string>
#include "../StatmentParser/StatementParser.h"
using namespace std;

class Literal{
    string m_symbol;
    TokenType m_type;
public:
    Literal(Definition* definition);

    int m_key;
};

class DataObject {
public:
    DataObject(Query* query);

    map<string,Literal*> m_definitions;
};



#endif //FAKESQL_DATAOBJECT_H
