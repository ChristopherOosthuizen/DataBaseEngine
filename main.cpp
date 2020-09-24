#include <iostream>
#include <list>
#include "FakeSql/Parser/Parser.h"
#include "FakeSql/StatmentParser/StatementParser.h"
#include "FakeSql/Model/Model.h"
#include "FakeSql/Model/bTree.h"
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
    /*string* input = new string;
    while(1){
        std::cout << ">";
        readLine(input);
        if(!input->compare(":q\n"))
            break;
        Parser parser(input);
        auto* tokens = new std::list<Token*>;
        while(!parser.isDone()){
            Token* token = parser.next();
            tokens->push_back(token);
        }
        try {
            StatementParser stat(tokens);
            stat.next()->print();
        }catch(string& e ){
            std::cout<<e<<"\n";
        }
        *input ="";
    }
    delete input;*/

    BTree t(3);




}

