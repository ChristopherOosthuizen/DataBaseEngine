#include <iostream>
#include <signal.h>
#include <list>
#include<thread>
#include <StatmentRunner/Instance.h>
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

void handleConnection(int sock,Instance* instance){
    string* input = new string;
    chdir(ServSock::readAll(sock).c_str());

    while(1){
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

        if(!stat.isFinished()) {
            Statement *expression = stat.next();
            string result = instance->handle(expression);
            ServSock::write(sock,result);
        }
        else
            ServSock::write(sock,"No input");

        }catch(string& e ){
            ServSock::write(sock,"\n"+e+"\n");
        }
        *input ="";
    }
    delete input;
}
void sigpipe_handler(int unused)
{
}

int main(void) {
    signal(SIGPIPE, sigpipe_handler);
    Instance* inst = new Instance;
    ServSock sock(8080);
    while(1) {
            int soc = sock.connect();
            thread name(handleConnection,soc, inst);
            name.detach();
    }
    return 1;

}


