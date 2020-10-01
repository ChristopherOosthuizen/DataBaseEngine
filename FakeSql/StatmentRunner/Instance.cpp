//
// Created by Chris on 9/24/2020.
//

#include "Instance.h"

string Instance::handle(Expression *expression) {
    switch(expression->m_command->m_token->m_type) {
        case TokenType::CREATE:   return handleCreate(expression);
        case TokenType::SEARCH: return handleSearch(expression);
        default:return "FAILED UNKOWN COMMAND";
    }
}
string Instance::handleCreate(Expression *expression) {
    if(expression->m_type->m_token->m_type == TokenType::MODEL){
        (m_models)[expression->m_query->m_token->m_symbol] = new Model(expression);
        return "MADE data";
    }else{
        Model* model = (m_models)[expression->m_query->m_token->m_symbol];
        if(model == nullptr)
            throw string("UNKNOWN MODEL");
        model->insert(expression->m_query);
        return "inserted data";
    }
    return "SUCCESS";
}
string Instance::handleSearch(Expression *expression) {
    if(expression->m_type->m_token->m_type == TokenType::MODEL){
        return "UNKOWN";
    }else{
        Model* model = (m_models)[expression->m_query->m_token->m_symbol];
        if(model == nullptr)
            throw string("UNKNOWN MODEL");
        model-
    }
}
