//
// Created by Chris on 9/19/2020.
//

#include "DataSlot.h"


DataSlot::DataSlot(const std::string &str) {
    m_type = findType(str);
    m_searchTrees =  std::map<std::string, BTree<std::string>*>();

}

DataType DataSlot::findType(const std::string &str) {
    if(str =="INT"){
        return DataType::INT;
    }
    else if(str == "BOOL")
        return DataType::BOOL;
    return DataType::STRING;
}