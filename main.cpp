#include <iostream>
#include <list>
#include <StatmentRunner/Instance.h>
#include "FakeSql/Parser/Parser.h"
#include "FakeSql/StatmentParser/StatementParser.h"
#include "FakeSql/Model/Model.h"
#include "FakeSql/Model/bTree.h"
#include "Server/ServSock.h"
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

void handleConnection(SOCKET sock,Instance* instance){
    string* input = new string;
    while(1){
        std::cout << ">";
        *input = ServSock::readAll(sock);
        if((input->at(0) ==':' && input->at(1)=='q'))
            break;
        try {
        Parser parser(input);
        auto* tokens = new std::list<Token*>;
        while(!parser.isDone()){
            Token* token = parser.next();
            tokens->push_back(token);
        }
            StatementParser stat(tokens);
            Statement* expression = stat.next();
            ServSock::write(sock,instance->handle(expression));
        }catch(string& e ){
            ServSock::write(sock,"\n"+e+"\n");
        }
        *input ="";
    }
    delete input;
}

int main() {
    Instance* inst = new Instance;
    ServSock sock("8080");
    while(1) {
        SOCKET soc = sock.connect();
        handleConnection(soc, inst);
        sock.close(soc);
    }

}


