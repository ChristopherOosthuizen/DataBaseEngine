//
// Created by Chris on 9/19/2020.
//

#ifndef FAKESQL_DATASLOT_H
#define FAKESQL_DATASLOT_H
#include <map>
#include <string>
#include "BTreeAct.h"

enum class DataType{INT,STRING,BOOL};
template <class T>
        class BTree;
class DataSlot{
    DataType m_type;
    std::map<std::string, BTree<std::string>*> m_searchTrees;
public:
    DataSlot(const std::string& str);
    DataType findType(const std::string& str);

    friend class DataObject;
};

struct DataObject{
    std::map<std::string,void*> m_values;
    DataType m_type;
};


#endif //FAKESQL_DATASLOT_H
