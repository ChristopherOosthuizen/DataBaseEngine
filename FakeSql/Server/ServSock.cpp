//
// Created by Chris on 9/27/2020.
//



#include <cstdio>
#include <iostream>
#include <unistd.h>
#include "ServSock.h"
ServSock::ServSock(int port){
    int opt = 1;
    int addrlen = sizeof(m_address);
    char buffer[1024] = {0};
    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    m_addrlen = sizeof(m_address);
    setsockopt(m_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) ;
    m_address.sin_family = AF_INET;
    m_address.sin_addr.s_addr = INADDR_ANY;
    m_address.sin_port = htons( port );
    bind(m_socket, (struct sockaddr *)&m_address,m_addrlen);
    listen(m_socket, 3);
};
int ServSock::connect(){
    return accept(m_socket, (struct sockaddr *)&m_address,(socklen_t*)&m_addrlen);
};
char ServSock::read(int sock){
    char buffer[1] = {0};
    ::read(sock, buffer,1);
    return buffer[0];
};
void ServSock::write(int sock,std::string message){
    send(sock,message.c_str(),message.length(),0);
};

std::string ServSock::readAll(int sock) {
    std::string result;
    char c=read(sock);
    int count =0;
    do{
        if(c != -52) {
            result += c;
        }else{
            count++;
            sleep(400);
        }
        if(count == 500){
            throw std::string("Connection timed out");
        }
        c = read(sock);
    }while(c == -52 || c !='\a');
    return result;
}

