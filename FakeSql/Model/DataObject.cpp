//
// Created by Chris on 9/23/2020.
//

#include <sstream>
#include "DataObject.h"

Literal::Literal(Definition *definition) {
    m_symbol = definition->m_val->m_token->m_symbol;
    m_type = definition->m_val->m_token->m_type;
    stringstream stream(m_symbol);
    switch(m_type){
        case TokenType::BOOL: m_key = "TRUE"== m_symbol?1:0;break;
        case TokenType::STRING:
            hash<string> hasher;
            m_key = hasher(m_symbol);
            break;
        case TokenType::DOUBLE:
            stream >>m_key;break;
        default:
            StatementParser::throwError("Unknown type",definition->m_iden);
    }
}
DataObject::DataObject(Query *query) {
    for(auto del:*query->m_block->m_definitions){
        m_definitions[del->m_iden->m_symbol] =new Literal(del);
    }
}