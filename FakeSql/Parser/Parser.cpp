//
// Created by Chris on 9/19/2020.
//

#include "Parser.h"

#include <utility>

Parser::Parser(string* str) {
    m_content = str;
    m_curr =0;
    m_id=0;
    m_isDone =0;
    m_pos =0;
    m_line =0;
}

Token* Parser::next() {
    char c = advance();
    m_id+=1;
    switch (c) {
        case '{':return new Token("{",TokenType::OPENING_BRACE,m_id,m_line,m_pos);
        case '}':return new Token("}",TokenType::CLOSING_BRACE,m_id,m_line,m_pos);
        case '\n':m_line++;
            m_pos=0;
            m_id--;
              return new Token("\\n",TokenType::NEW_LINE,m_id,m_line,m_pos);
        case ';':return new Token(";",TokenType::SEMICOLIN,m_id,m_line,m_pos);
        case ':':
            switch(peek()){
                case 'e': advance(); return new Token(":e",TokenType::EDIT,m_id,m_line,m_pos-1);
                case 'd':advance(); return new Token(":d",TokenType::DELETE,m_id,m_line,m_pos-1);
                case 'c':advance(); return new Token(":c",TokenType::CREATE,m_id,m_line,m_pos-1);
                case 's':advance(); return new Token(":s",TokenType::SEARCH,m_id,m_line,m_pos-1);
            }
            return new Token(":",TokenType::COLIN,m_id,m_line,m_pos);
        case '\b':
        case '\0':
        case ' ': m_id--;
            return next();
        case '"': return findString();
    }
    if( (c >='1'&&c <='9'))
        return findNumber(c);
    if(((c >='A'&&c <='Z')||(c >='a'&&c<='z')))
        return findIden(c);
    throw string("UNKOWN char  "+c);
    return NULL;



}
Token* Parser::findNumber(char c) {
    string result;
    result +=c;
    while(peek() !=0 && ((peek() >='0'&&peek() <='9'))){
        result +=advance();
    }
    return new Token(result,TokenType::DOUBLE,m_id,m_line,m_pos);

}
Token* Parser::findIden(char c) {
    string result;
    result +=c;
    int start =m_pos;
    while(peek() !=0 && ((peek() >='A'&&peek() <='Z')||(peek() >='a'&&peek()<='z'))){
        result +=advance();
    }
    if(s_keys[result] != (TokenType)NULL){
        return new Token(result,s_keys[result],m_id,m_line,start);
    }
    return new Token(result,TokenType::IDEN,m_id,m_line,start);


}
Token* Parser::findString(){
    char c = advance();
    string result;
    while(c !=0 && c !='"'){
        result +=c;
        c= advance();
    }
    return new Token(result,TokenType::STRING,m_id,m_line,m_pos);
}

char Parser::advance() {

    if(m_isDone)
        return 0;
    if(m_content->length()-1 <= m_curr){
        m_isDone = 1;
        return m_content->at(m_curr);
    }
    m_pos++;
    char c =m_content->at(m_curr++);
    return c;
}

char Parser::peek() {
    if(isDone())
        return 0;
    return m_content->at(m_curr);
}



int Parser::isDone(){
    return m_isDone|| (m_content->length() <=m_curr);
}

Token::Token(string symbol, TokenType type, int id,int line,int pos) {
    m_symbol = symbol;
    m_type = type;
    m_id = id;
    m_pos = pos;
    m_line =line;
}

void Token::toString() {
    printf("ID: %d SYMBOL: %s TYPE %d LINE:%d pos:%d\n",m_id,m_symbol.c_str(),m_type,m_line,m_pos);
}
