//
// Created by Chris on 9/20/2020.
//

#include "StatementParser.h"

Token* StatementParser::advance() {

    if(isFinished()){

        return NULL;
    }
    return *(m_it++);
}

Token *StatementParser::peek() {
    Token* adv = advance();
    back();
    return adv;
}



StatementParser::StatementParser(list<Token *> *tokens) {
    m_tokens = tokens;
    m_it = tokens->begin();
}

Statement *StatementParser::next() {
    Token* token = advance(TokenType::NEW_LINE);
    if(token == NULL){
        throw string("At END");
    }
    switch(token->m_type){
        case TokenType::DELETE:
        case TokenType::SEARCH:
        case TokenType::CREATE:
        case TokenType::EDIT:
            return createExpression( token);
        case TokenType::LOAD:
        case TokenType::SAVE:
            return createLoad(token);
    }
    throwError("UNKNOWN command",token);
    return nullptr;
}
Expression* StatementParser::createExpression(Token* token){
    Command* command = new Command(token);
    Type* type = new Type(advance());
    Query* quarry = createQuery();
    return new Expression(command,type,quarry);
}

Query* StatementParser::createQuery() {
    Token* iden = advance();
    match(iden,TokenType::IDEN,"INVALID identifier");
    return new Query(iden,createBlock());
}
Block* StatementParser::createBlock() {
    Token* token = advance();
    auto* definitions = new list<Definition*>;
    if(token == NULL ||token->m_type == TokenType::OPENING_BRACE){
        while(!isFinished() &&(peek()->m_type) != TokenType::CLOSING_BRACE){
            definitions->push_back(createDefinition());
        }
        advance();
    }else{
        while(!isFinished() &&(peek()->m_type) != TokenType::NEW_LINE){
            definitions->push_back(createDefinition());
        }
        advance();
    }
    return new Block(definitions);
}
int StatementParser::isFinished() {
    int result = (m_it) == m_tokens->end()||(m_it) == --m_tokens->end() ;
    return result;
}

Definition *StatementParser::createDefinition() {
    Token* iden = advance(TokenType::NEW_LINE);
    match(iden,TokenType::IDEN,"INVALID identifier");
    Token* colin =advance(TokenType::NEW_LINE);
    match(colin,TokenType::COLIN,"INVALID divider used");
    Value* val = new Value(advance(TokenType::NEW_LINE));
    Token* semicolin = advance(TokenType::NEW_LINE);
    match(semicolin, TokenType::SEMICOLIN, "INVALID No closer used");
    return new Definition(iden,val);
}

StatementParser::~StatementParser() {
    for(auto & m_token : *m_tokens){
        delete m_token;
    }
    delete m_tokens;
}

void StatementParser::throwError(const string &message,Token* token) {
    char buffer[100];
    std::sprintf(buffer,":%s at line:%d pos:%d",token->m_symbol.c_str(),token->m_line,token->m_pos);
    std::string str(buffer);
    throw message+str;
}

void StatementParser::match(Token *token, TokenType type,const string& message) {
    if(token ==NULL)
        throw string("UNCLOSED statement");
    if(token->m_type != type){
        throwError(message,token);
    }
}

Token *StatementParser::advance(TokenType ignore) {
    Token* token =advance();
    while(token != NULL &&token->m_type == ignore)
        token = advance();
    return token;
}

Loader *StatementParser::createLoad(Token* origin) {
    Token* token = advance();
    match(token,TokenType::STRING,"UNKOWN type");
    return new Loader(origin,token);
}

Token *StatementParser::back() {

    return *(m_it--);
}

Type::Type(Token *token) {
    switch(token->m_type){
        case TokenType::DATA_OBJECT:
        case TokenType::MODEL:
            break;
        default:StatementParser::throwError("INVALID Type",token);
    }
    m_token = token;
}

void Statement::run() {

}

Value::Value(Token *token) {
    if(token == NULL)
        throw string("wrong");
    switch(token->m_type){
        case TokenType::STRINGIDEN:
        case TokenType::NUM:
        case TokenType::DOUBLE:
        case TokenType::STRING:
        case TokenType::BOOL:
        case TokenType::BOOLIDEN:break;
        default: StatementParser::throwError("INVALID type",token);
    }
    m_token = token;
}
