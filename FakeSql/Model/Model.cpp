//
// Created by Chris on 9/22/2020.
//

#include "Model.h"

Model::Model(Expression *expression) {
    m_name = expression->m_query->m_token->m_symbol;
    for(const auto& del: *expression->m_query->m_block->m_definitions){
        m_values[del->m_iden->m_symbol] = new BTree(3);
    }
}

void Model::insert(Query *query) {
    auto* obj = new DataObject(query);
    for(const auto& del: obj->m_definitions){
        m_values[del.first]->insert(del.second->m_key,obj);
    }
}
