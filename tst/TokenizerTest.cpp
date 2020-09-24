//
// Created by Chris on 9/24/2020.
//

#include "gtest/gtest.h"
#include "Parser/Parser.h"
#include "list"
using namespace std;
TEST(Tokenizer,lengths){
    string* str = new string("EDIT MODEL name {{{{chris:name\"hello\"there}}}\n");
    Parser one(str);
    list<Token*>* tokens = new list<Token*>;
    while(!one.isDone()){
        tokens->push_back(one.next());

    }
    EXPECT_EQ(tokens->size(),16);
    delete tokens;
    delete str;
    str = new string("\"how are you\":right:left:MODEL: \n\n\n");
    Parser two(str);
     tokens = new list<Token*>;
    while(!two.isDone()){
        tokens->push_back(two.next());
    }
    EXPECT_EQ(tokens->size(),11);
    delete tokens;
    delete str;
    str = new string("\"\"12345\"\"::::123;;544;;");
    Parser three(str);
    tokens = new list<Token*>;
    while(!three.isDone()){
        tokens->push_back(three.next());
    }
    EXPECT_EQ(tokens->size(),13);
}

TEST(Type, commands){
    string* str = new string("EDIT CREATE SEARCH DELETE");
    Parser one(str);
    EXPECT_EQ(one.next()->m_type,TokenType::EDIT);
    EXPECT_EQ(one.next()->m_type,TokenType::CREATE);
    EXPECT_EQ(one.next()->m_type,TokenType::SEARCH);
    EXPECT_EQ(one.next()->m_type,TokenType::DELETE);
    delete str;
    str = new string(":e :c :s :d");
    Parser two(str);
    EXPECT_EQ(two.next()->m_type,TokenType::EDIT);
    EXPECT_EQ(two.next()->m_type,TokenType::CREATE);
    EXPECT_EQ(two.next()->m_type,TokenType::SEARCH);
    EXPECT_EQ(two.next()->m_type,TokenType::DELETE);
}
TEST(Real,test){
    string* str = new string(":e MODEL name {chris:NUM;}\n");
    Parser parser(str);
    EXPECT_EQ(parser.next()->m_type,TokenType::EDIT);
    EXPECT_EQ(parser.next()->m_type,TokenType::MODEL);
    EXPECT_EQ(parser.next()->m_type,TokenType::IDEN);
    EXPECT_EQ(parser.next()->m_type,TokenType::OPENING_BRACE);
    EXPECT_EQ(parser.next()->m_type,TokenType::IDEN);
    EXPECT_EQ(parser.next()->m_type,TokenType::COLIN);
    EXPECT_EQ(parser.next()->m_type,TokenType::NUM);
    EXPECT_EQ(parser.next()->m_type,TokenType::SEMICOLIN);
    EXPECT_EQ(parser.next()->m_type,TokenType::CLOSING_BRACE);
}
TEST(Type,identifiers){
    string* str = new string("name \"hello\"1234STRING BOOL TRUE NUM");
    Parser parser(str);
    EXPECT_EQ(parser.next()->m_type,TokenType::IDEN);
    EXPECT_EQ(parser.next()->m_type,TokenType::STRING);
    EXPECT_EQ(parser.next()->m_type,TokenType::DOUBLE);
    EXPECT_EQ(parser.next()->m_type,TokenType::STRINGIDEN);
    EXPECT_EQ(parser.next()->m_type,TokenType::BOOLIDEN);
    EXPECT_EQ(parser.next()->m_type,TokenType::BOOL);
    EXPECT_EQ(parser.next()->m_type,TokenType::NUM);
}