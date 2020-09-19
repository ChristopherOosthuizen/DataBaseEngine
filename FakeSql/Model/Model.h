//
// Created by Chris on 9/18/2020.
//

#ifndef FAKESQL_MODEL_H
#define FAKESQL_MODEL_H
#include <Map>
#include <string>
#include "bTree.h"
enum class DataType{INT,STRING,BOOL};
class Model {

    int m_size;
    std::string m_name;
public:
    Model(const std::string& str,  std::map<const std::string*,std::string*>* map);
    friend class DataSlot;
};



class DataSlot{
    DataType m_type;

    friend class DataObject;
};

class DataObject{
    std::map<std::string,void*> m_values;
};




#endif //FAKESQL_MODEL_H
