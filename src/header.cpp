#include "header.h"
#include <stdio.h>
#include "rechercheInformation.h"
#include <string.h>

Header::Header()
{
    host = path = referer = userAgent = accept = accept_language = accept_encoding = cookie = variable = connexion = if_None_Match = "";
    method = "GET";
}
const char* Header::getHostChar(bool removeHttp)
{
    if(removeHttp)
        return host.c_str();
    else return std::string("http://"+host).c_str();
}

std::string Header::getHostString(bool removeHttp)
{
    if(removeHttp)
        return host;
    else return "http://"+host;
}

void Header::addVariable(std::string variable,std::string value)
{
    if(value.find(" ") != std::string::npos)
    {
        std::string tampon = value;
        RechercheInfo::searchCutRight(&tampon," ",true);
        RechercheInfo::searchCutLeft(&value," ",true);
        value=tampon+'+'+value;
    }

    if(this->variable.compare(""))
        this->variable+="&";

    this->variable += variable + "="+value;

}

void Header::addCookie(std::string variable,std::string value)
{
    if(!cookieExist(variable))
    {
       if(this->cookie.compare(""))
        {
            this->cookie+=" ";
        }
        this->cookie += variable+"="+value+';';

    }else RechercheInfo::remplace(&cookie,variable,value);

}

bool Header::cookieExist(std::string variable)
{
    std::string tampn=cookie;
    RechercheInfo::searchCutLeft(&tampn,variable+'=',true);
    if(tampn.size()==0)return false; else return true;
}

void Header::setHost(std::string host)
{
    removeHttp(&host);
    this->host = host;
}

void Header::setPath(std::string past)
{
    removeHttp(&past);
    this->path = past;
}

void Header::removeHttp(std::string* adresse)
{
    if(adresse->find("http://")==0)
        adresse->replace(0,7,"");
    else if(adresse->find("https://")==0)
        adresse->replace(0,8,"");
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

