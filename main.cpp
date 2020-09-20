#include <iostream>
#include "FakeSql/Parser/Parser.h"


void readLine(string* str){
    char c=0;
    int isMultiLine =0;
    while(c !='\n'|| isMultiLine){
        c = (char)getchar();
        str->push_back(c);
        if(c =='{'){
            isMultiLine = 1;
        }else if(c == '}')
            isMultiLine =0;
    }
}

int main() {
    string* input = new string;
    do{
        std::cout << ">";
        readLine(input);
        Parser parser(input);
        while(!parser.isDone()){
            Token* token = parser.next();
            token->toString();
            delete token;
        }
    }while(input->compare(":q"));
    delete input;
}

