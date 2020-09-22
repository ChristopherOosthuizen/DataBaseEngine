//
// Created by Chris on 9/22/2020.
//

#ifndef FAKESQL_MODEL_H
#define FAKESQL_MODEL_H

#include <string>

using namespace std;
class Model {
    int m_id;


};
class Object{
public:
    Object(int id,const string& name){
        m_name = name;
        m_id =id;
    }

    int m_id;
    string m_name;
};


#endif //FAKESQL_MODEL_H
