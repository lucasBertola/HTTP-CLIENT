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

        //get the body and head of the page
        std::string getPage(Header* head);

    private:

        void ConnectSocket();
        std::string recvPaquet();

        void CreateSocket(Header head);

        unsigned int tailleHead(std::string page);
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
