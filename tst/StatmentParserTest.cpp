//
// Created by Chris on 9/24/2020.
//
#include <Parser/Parser.h>
#include "gtest/gtest.h"
#include <list>
#include <StatmentParser/StatementParser.h>

using namespace std;
TEST(OneParam,value){
    auto* str = new string("\"name\" BOOL STRING NUM 1234 TRUE FALSE MODEL");
    Parser one(str);
    for(int i=0; i<7;i++){
        Value type(one.next());
    }
    try{
        Value type(one.next());
        FAIL();
    }catch(string& str){

    }
}
TEST(OneParam, Block){
    string* str = new string("{chris:NUM; name:STRING;id:NUM;}");
    Parser one(str);
    list<Token*>* tokens = new list<Token*>;
    while(!one.isDone()){
        tokens->push_back(one.next());
    }
    StatementParser parsers(tokens);
    Block* block = parsers.createBlock();
    auto it = block->m_definitions->begin();
    EXPECT_EQ("chris",(*it)->m_iden->m_symbol);
    EXPECT_EQ("NUM",(*it)->m_val->m_token->m_symbol);
    ++it;
    EXPECT_EQ("name",(*it)->m_iden->m_symbol);
    EXPECT_EQ("STRING",(*it)->m_val->m_token->m_symbol);
    ++it;
    EXPECT_EQ("id",(*it)->m_iden->m_symbol);
    EXPECT_EQ("NUM",(*it)->m_val->m_token->m_symbol);
    delete str;
}
TEST(Block, errors){
    string* str = new string("{chris:NUM; name:STRING;id:NUM;");
    Parser one(str);
    list<Token*>* tokens = new list<Token*>;
    while(!one.isDone()){
        tokens->push_back(one.next());
    }
    StatementParser parsers(tokens);

    try{
        Block* block = parsers.createBlock();
        FAIL();
    }catch(string& str){

    }
}