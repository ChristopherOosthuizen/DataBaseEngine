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

