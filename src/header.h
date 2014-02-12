#ifndef HEADER_H
#define HEADER_H

#include <iostream>

class Header
{
    public:
        Header();
        void setHost(std::string host);
        void setPath(std::string path);
         void addVariable(std::string variable,std::string value);
        void addCookie(std::string variable,std::string value);


        void setCookie(std::string cookie)            {this->cookie = cookie;}
        void setReferer(std::string past)             {this->referer = past;}
        void setUserAgent(std::string past)           {this->userAgent = past;}
        void setAccept(std::string accepted)          {this->accept = accepted;}
        void setMethod(std::string method)            {this->method = method;}
        void setAccept_language(std::string lg)       {this->accept_language = lg;}
        void setAccept_encoding(std::string encoding) {this->accept_encoding = encoding;}
        void setConnexion(std::string past)           {this->connexion = host;}
        void setIfNotMatch(std::string iNm)           {this->if_None_Match = iNm;}

        void removeVariable(){ variable=""; }
        void removeCookie(){  cookie = ""; }

        const char* getHostChar(bool removeHttp=true);
        std::string getHostString(bool removeHttp=true);

        std::string getPathString()      {return path;}
        std::string getRefererString()   {return referer;}
        std::string getUserAgent()       {return userAgent;}
        std::string getAccept()          {return accept;}
        std::string getMethod()          {return method;}
        std::string getCookie()          {return cookie;}
        std::string getAccept_language() {return accept_language;}
        std::string getAccept_encoding() {return accept_encoding;}
        std::string getVariable()        {return variable;}
        std::string getConnexion()       {return connexion;}
        std::string getIfnotMatch()      {return if_None_Match;}



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
