//
// Created by Chris on 9/19/2020.
//

#ifndef FAKESQL_PARSER_H
#define FAKESQL_PARSER_H
#include <string>
#include <map>
 enum class TokenType{IDEN,NUM,STRINGIDEN,STRING,BOOLIDEN,BOOL,MODEL,OPENING_BRACE,CLOSING_BRACE,DATA_OBJECT,NEW_LINE,SEMICOLIN,COLIN,DOUBLE,CREATE,DELETE,EDIT,SEARCH,LOAD,SAVE};
using namespace std;
class Parser {
    string* m_content;
    int m_curr;
    int m_id;
    int m_isDone;
    int m_pos;
    int m_line;
    map<string,TokenType> s_keys = {{"STRING",TokenType::STRINGIDEN},{"NUM",TokenType::NUM},{"BOOL",TokenType::BOOLIDEN},{"MODEL",TokenType::MODEL},{"OBJECT",TokenType::DATA_OBJECT},{"TRUE",TokenType::BOOL},{"FALSE",TokenType::BOOL},{"CREATE",TokenType::CREATE},{"EDIT",TokenType::EDIT},{"SEARCH",TokenType::SEARCH},{"DELETE",TokenType::DELETE},{"LOAD",TokenType::LOAD},{"SAVE",TokenType::SAVE}};
    friend struct Token;
    char advance();
    char peek();
    Token* findString();
    Token* findNumber(char c);
    Token* findIden(char c);

public:
    explicit Parser(string* str);
    Token* next();
    int isDone();


};
class Token{

public:
    int m_id;
    int m_line;
    int m_pos;
    string m_symbol;
    TokenType m_type;
    Token(string symbol,TokenType type,int id,int line,int pos);
    void toString();
};

#endif //FAKESQL_PARSER_H
