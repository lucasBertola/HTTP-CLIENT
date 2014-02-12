#include "header.h"
#include <stdio.h>
#include "rechercheInformation.h"
#include <string.h>
Header::Header()
{
    host="";
    path="";
    referer="";
    userAgent="";
    accept="";
    accept_language="";
    accept_encoding="";
    cookie="";
    method="GET";
    variable="";
    connexion="";
    if_None_Match="";
}
const char* Header::getHostChar(bool removeHttp)
{
    std::string p;

    if(removeHttp)
    {
        p= host;
    }else p= "http://"+host;


    return p.c_str();
}
std::string Header::getHostString(bool removeHttp)
{
    if(removeHttp)
    {
        return host;
    }else return "http://"+host;


}
std::string Header::getPathString()
{
    return path;

}
std::string Header::getConnexion()
{
    return connexion;

}
std::string Header::getMethod()
{
    return method;

}
std::string Header::getUserAgent()
{
    return userAgent;

}
std::string Header::getVariable()
{
    return variable;

}
std::string Header::getRefererString()
{
    return referer;

}
std::string Header::getAccept()
{
    return accept;

}
void Header::addVariable(std::string variable,std::string value)
{
    int nb=value.find(" ");
    if(nb<=value.size())
    {
        std::string tampon=value;
        RechercheInfo::searchCutRight(&tampon," ",true);
        RechercheInfo::searchCutLeft(&value," ",true);
        value=tampon+'+'+value;
    }

    if(this->variable.compare(""))
    {
        this->variable+="&";
    }else
    {

    }
    this->variable+=variable+"="+value;
}
void Header::addCookie(std::string variable,std::string value)
{
    if(!cookieExist(variable))
    {
       if(this->cookie.compare(""))
        {
            this->cookie+=" ";
        }
        this->cookie+=variable+"="+value+';';
    }else
    RechercheInfo::remplace(&cookie,variable,value);

}
bool Header::cookieExist(std::string variable)
{
    std::string tampn=cookie;
    RechercheInfo::searchCutLeft(&tampn,variable+'=',true);
    if(tampn.size()==0)return false; else return true;
}
std::string Header::getCookie()
{
    return cookie;

}
std::string Header::getIfnotMatch()
{
    return if_None_Match;

}
std::string Header::getAccept_language()
{
    return accept_language;

}
std::string Header::getAccept_encoding()
{
    return accept_encoding;

}
void Header::setHost(std::string host)
{
    removeHttp(&host);
    this->host = host;
}
void Header::setAccept(std::string host)
{
    this->accept = host;
}
void Header::setMethod(std::string host)
{
    this->method = host;
}
void Header::setCookie(std::string host)
{

    this->cookie = host;
}
void Header::setIfNotMatch(std::string host)
{

    this->if_None_Match = host;
}

void Header::setConnexion(std::string host)
{

    this->connexion = host;
}
void Header::setAccept_language(std::string host)
{

    this->accept_language = host;
}
void Header::setAccept_encoding(std::string host)
{

    this->accept_encoding = host;
}
void Header::setPath(std::string past)
{
    removeHttp(&past);
    this->path = past;
}
void Header::setReferer(std::string past)
{

    this->referer = past;
}
void Header::setUserAgent(std::string past)
{
    this->userAgent = past;
}
void Header::removeHttp(std::string* adresse)
{
    if(adresse->find("http://")==0)
    {
        adresse->replace(0,7,"");

    }else if(adresse->find("https://")==0)
    {
        adresse->replace(0,8,"");

    }
}
void Header::removeVariable()
{
    variable="";
}

void Header::removeCookie() {
    cookie = "";
}
void Header::removeHttp(char adresse[])
{
    std::string dd=adresse;
    if(dd.find("http://")==0)
    {
        dd.replace(0,7,"");

        strcpy(adresse, dd.c_str());
    }else if(dd.find("https://")==0)
    {
        dd.replace(0,8,"");

        strcpy(adresse, dd.c_str());
    }
}

