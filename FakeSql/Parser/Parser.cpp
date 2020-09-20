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
            return new Token("\\n",TokenType::ENDLINE,m_id,m_line,m_pos);
        case ';':return new Token(";",TokenType::SEMICOLIN,m_id,m_line,m_pos);
        case ':': return new Token(":",TokenType::COLIN,m_id,m_line,m_pos);
        case ' ': m_id--;
            return next();
        case '"': return findString();
    }
    if( (c >='1'&&c <='9'))
        return findNumber(c);
    return findIden(c);



}
Token* Parser::findNumber(char c) {
    string result;
    while(c !=0 && ((c >='1'&&c <='9'))){
        result +=c;
        c= advance();
    }
    return new Token(result,TokenType::DOUBLE,m_id,m_line,m_pos);

}
Token* Parser::findIden(char c) {
    string result;
    result+=c;
    c = advance();
    while(c !=0 && ((c >='A'&&c <='Z')||(c >='a'&&c<='z') )){
        result +=c;
        c= advance();
    }
    if(s_keys[result] != (TokenType)NULL){
        return new Token(result,s_keys[result],m_id,m_line,m_pos);
    }
    return new Token(result,TokenType::IDEN,m_id,m_line,m_pos);


}
Token* Parser::findString(){
    char c = advance();
    string result;
    while(c !=0 && c !='\n'){
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
    return m_content->at(m_curr++);
}

char Parser::peek() {

    return m_content->at(m_curr);
}



int Parser::isDone(){
    return m_isDone;
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
