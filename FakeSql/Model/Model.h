//
// Created by Chris on 9/22/2020.
//

#ifndef FAKESQL_MODEL_H
#define FAKESQL_MODEL_H

#include <string>
#include "DataObject.h"
#include "bTree.h"

using namespace std;
class Model {
    map<string,BTree*> m_values;
    string m_name;

public:
    Model(Expression* expression);

    void insert(Query* query);
};


#endif //FAKESQL_MODEL_H
