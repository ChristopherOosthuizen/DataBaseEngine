//
// Created by Chris on 9/18/2020.
//

#include "Model.h"
Model::Model(const std::string& str,  std::map<std::string,std::string>* temp){
    m_name = str;
    m_values = new std::map<std::string, DataSlot*>();
    for(auto it = temp->begin();it != temp->end();it++){
        (*m_values)[it->first] = new DataSlot(it->second);
    }
}

DataSlot::DataSlot(const std::string &str) {
    m_type = findType(str);
    m_searchTrees =  std::map<std::string, DataSlot*>();
}

DataType DataSlot::findType(const std::string &str) {
    if(str =="INT"){
        return DataType::INT;
    }
    else if(str == "BOOL")
        return DataType::BOOL;
    return DataType::STRING;
}