#ifndef COUCHEHTTP_H
#define COUCHEHTTP_H

#include <WinSock2.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "header.h"


class Http
{
    public:
        Http(Header head);
        ~Http();

        std::string getPage(Header* head);
        std::string recvPaquet();
        void ConnectSocket();
    private:

        void CreateSocket(Header head);
        int tailleHead(std::string page);
        int hexaTodecimal(std::string hexa);
        SOCKET sock;
        SOCKADDR_IN sin;

        WSADATA WSAData;
        void redirection(Header* head,std::string* reponce);
        int recvTimeOut(int s,  int millisecond,std::string *chaine);


        void sendPaquet(Header head);
        void getCookie(Header* head,std::string reponce);

};

#endif // COUCHEHTTP_H
