#ifndef HEADER_H
#define HEADER_H

#include <iostream>

class Header
{
    public:
        Header();
        void setHost(std::string host);
        void setPath(std::string path);
        void setCookie(std::string path);
        void setReferer(std::string ref);
        void setUserAgent(std::string ref);
        void setAccept(std::string ref);
         void setMethod(std::string ref);
        void setAccept_language(std::string ref);
        void setAccept_encoding(std::string ref);
        void setConnexion(std::string ref);
        void addVariable(std::string variable,std::string value);
        void addCookie(std::string variable,std::string value);
        void setIfNotMatch(std::string ref);

        void removeVariable();
        void removeCookie();

        const char* getHostChar(bool removeHttp=true);
        std::string getHostString(bool removeHttp=true);

        std::string getPathString();
        std::string getRefererString();
        std::string getUserAgent();
        std::string getAccept();
        std::string getMethod();
        std::string getCookie();
        std::string getAccept_language();
        std::string getAccept_encoding();
        std::string getVariable();
        std::string getConnexion();
        std::string getIfnotMatch();



    private:
        bool cookieExist(std::string variable);
        std::string connexion;
        std::string variable;
        std::string method;
        std::string cookie;
        std::string accept_encoding;
        std::string accept_language;
        std::string accept;
        std::string referer;
        std::string host;
        std::string userAgent;
        std::string path;
        std::string if_None_Match;

        void removeHttp(std::string* s);
        void removeHttp(char s[]);

};


#endif // HEADER_H
