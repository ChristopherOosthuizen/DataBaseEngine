//
// Created by Chris on 9/18/2020.
//

#ifndef FAKESQL_MODEL_H
#define FAKESQL_MODEL_H
#include <map>
#include <string>
#include "bTree.h"
enum class DataType{INT,STRING,BOOL};
class DataSlot;
class bTree;
class Model {

    std::string m_name;
    std::map<std::string, DataSlot *>* m_values;
public:

    Model(const std::string& str,  std::map< std::string,std::string>* temp);
    friend class DataSlot;
};



class DataSlot{
    DataType m_type;
    std::map<std::string, DataSlot*> m_searchTrees;
public:
    DataSlot(const std::string& str);
    DataType findType(const std::string& str);

    friend class DataObject;
};

struct DataObject{
    std::map<std::string,void*> m_values;
    DataType m_type;
};




#endif //FAKESQL_MODEL_H
