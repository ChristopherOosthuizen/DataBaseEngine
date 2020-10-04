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
public:
    map<string,BTree*> m_values;
    string m_name;
    list<DataObject*>* m_objects;
    map<string,string> m_keys;

    Model(Expression* expression);
    ~Model(){delete m_objects;}
    void insert(Query* query);
    list<DataObject*>* search(Query* query);
    string toString();

};


#endif //FAKESQL_MODEL_H
