#ifndef COUCHEHTTP_H
#define COUCHEHTTP_H

#if defined(WIN32)
    # include <WinSock2.h>
#else if defined(UNIX)

    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h> /* close */
    #include <netdb.h> /* gethostbyname */
    #define INVALID_SOCKET -1
    #define SOCKET_ERROR -1
    #define closesocket(s) close(s)
    typedef int SOCKET;
    typedef struct sockaddr_in SOCKADDR_IN;
    typedef struct sockaddr SOCKADDR;
    typedef struct in_addr IN_ADDR;


#endif

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

        void redirection(Header* head,std::string* reponce);
        int recvTimeOut(unsigned int s,  int millisecond,std::string *chaine);


        void sendPaquet(Header head);
        void getCookie(Header* head,std::string reponce);

};

#endif // COUCHEHTTP_H
