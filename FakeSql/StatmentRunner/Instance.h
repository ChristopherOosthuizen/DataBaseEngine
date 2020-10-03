//
// Created by Chris on 9/24/2020.
//

#ifndef FAKESQL_INSTANCE_H
#define FAKESQL_INSTANCE_H

#include <map>
#include <string>
#include <Model/Model.h>

using namespace std;
class Instance {
    map<string,Model*> m_models;
public:
    string handle(Statement* expression);
    string handleCreate(Expression* expression);
    string handleSearch(Expression* expression);
};


#endif //FAKESQL_INSTANCE_H
