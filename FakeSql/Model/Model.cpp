//
// Created by Chris on 9/22/2020.
//

#include "Model.h"

Model::Model(Expression *expression) {
    m_name = expression->m_query->m_token->m_symbol;
    m_objects = new list<DataObject*>;
    for(const auto& del: *expression->m_query->m_block->m_definitions){
        m_values[del->m_iden->m_symbol] = new BTree(3);
    }
}

void Model::insert(Query *query) {
    auto* obj = new DataObject(query);
        for (const auto &del: obj->m_definitions) {
            BTree* mod = m_values[del.first];
            if(mod == nullptr){
                delete obj;
                throw string("unknown field");
            }
            mod->insert(del.second->m_key, obj);
        }
        m_objects->push_back(obj);
}
list<DataObject*>* Model::search(Query *query) {
    list<DataObject*>* objects = nullptr;
    if(query->m_block->m_definitions->empty()){
        return m_objects;
    }
    DataObject obj(query);
    for(auto del:obj.m_definitions){
        list<DataObject*>* temp = m_values[del.first]->findAll(del.second->m_key);
        if(objects == nullptr){
            objects = temp;
        }else{
            list<DataObject*>* act = new list<DataObject*>;
            for(DataObject* objs:*objects){
                if(std::find(temp->begin(),temp->end(),objs) != temp->end()){
                    act->push_back(objs);
                }

            }
            delete objects;
            delete temp;
            objects = act;
        }
    }
    return objects;
}