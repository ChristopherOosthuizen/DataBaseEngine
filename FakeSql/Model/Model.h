//
// Created by Chris on 9/18/2020.
//

#ifndef FAKESQL_MODEL_H
#define FAKESQL_MODEL_H
#include <map>
#include <string>
#include "bTree.h"
enum class DataType{INT,STRING,BOOL};
class Model {

    std::string m_name;
    std::map<const std::string&, DataSlot*> *m_values;
public:
    Model(const std::string& str,  std::map<const std::string*,const std::string&>* temp);
    friend class DataSlot;
};



class DataSlot{
    DataType m_type;
    std::map<const std::string&, bTree*>* m_searchTrees;
public:
    DataSlot(const std::string& str);
    DataType findType(const std::string& str);
    friend class DataObject;
};

class DataObject{
    std::map<std::string,void*> m_values;
    DataType m_type;
};




#endif //FAKESQL_MODEL_H
