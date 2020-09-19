//
// Created by Chris on 9/18/2020.
//

#ifndef FAKESQL_MODEL_H
#define FAKESQL_MODEL_H
#include <map>
#include <string>
#include "DataSlot.h"
class DataSlot;
class Model {

    std::string m_name;
    std::map<std::string, DataSlot *>* m_values;
public:

    Model(const std::string& str,  std::map< std::string,std::string>* temp);
};







#endif //FAKESQL_MODEL_H
