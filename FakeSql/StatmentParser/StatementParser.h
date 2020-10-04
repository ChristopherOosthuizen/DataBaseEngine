//
// Created by Chris on 9/20/2020.
//

#ifndef FAKESQL_STATEMENTPARSER_H
#define FAKESQL_STATEMENTPARSER_H
#include "../Parser/Parser.h"
#include <list>
#include <iostream>


using namespace std;
class Statement{
public:
    virtual void run();
};
class Value: public Statement{
public:
    Token* m_token;

    Value(Token* token);

};
class Command: public Statement{
public:
    Token* m_token;
    explicit Command(Token* token){
        m_token = token;
    }
};
class  Loader: public Statement{
public:
    Token* m_command;
    Token* m_address;
    explicit Loader(Token* command,Token* address){
        m_command = command;
        m_address = address;
    }
};
class Type: public Statement{
public:
    Token* m_token;
    explicit Type(Token* token);
};
class Definition:public Statement{
public:
    Token* m_iden;
    Value* m_val;
    Definition(Token* iden,Value* value ){
        m_iden = iden;
        m_val= value;
    }
};
class Block: public Statement{
public:
    list<Definition*>* m_definitions;
    Block(list<Definition*>* list){
        m_definitions = list;
    }
};
class Query:public  Statement{
public:
    Block* m_block;
    Token* m_token;

    Query(Token* iden, Block* block){
        m_block = block;
        m_token = iden;
    }
};
class Expression:public  Statement{
public:
    Command* m_command;
    Type* m_type;
    Query* m_query;
    Expression(Command* command,Type* type, Query* query){
        m_command = command;
        m_type = type;
        m_query = query;
    }
    ~Expression(){
        delete m_command;
        delete m_type;
        delete m_query;
    }
    void print(){
        cout<<m_command->m_token->m_symbol<<" "<<m_type->m_token->m_symbol<<" "<<m_query->m_token->m_symbol<<"\n";
    }

};


class StatementParser {
    list<Token*>* m_tokens;
    list<Token*>::iterator m_it;
    Token* advance();
    Token* advance(TokenType ignore);
    Token* peek();
    Token* back();
public:
    friend class Expression;
    static void throwError(const string& message,Token* token);
    static void match(Token* token, TokenType type,const string& str);
    explicit StatementParser(list<Token*>* tokens);
    ~StatementParser();
    Statement* next();
    int isFinished();
    Expression* createExpression(Token* token);
    Query* createQuery();
    Block* createBlock();
    Loader* createLoad(Token* origin);
    Definition* createDefinition();

};






#endif //FAKESQL_STATEMENTPARSER_H
