#include "rechercheInformation.h"
#include <string>
void RechercheInfo::searchCutLeft(std::string* sentence,std::string sentenceToSearch,bool cutSentenceToSearch)
{
   unsigned int nb=sentence->find(sentenceToSearch);
   if(nb>sentence->size())
   {

       sentence->replace(0,sentence->size(),"");
       return;
   }
   nb+=(cutSentenceToSearch)?sentenceToSearch.size():0;
   sentence->replace(0,nb,"");
}
//utiliser dans les cookiespour remlacer une valeur de cookie apr un atre
void RechercheInfo::remplace(std::string* sentence,std::string variable,std::string value)
{
    std::string tampon=*sentence;
    int nb=tampon.find(variable+'=');
    std::string offset =variable+'=';
    RechercheInfo::searchCutLeft(&tampon,variable+'=',true);
    int nb2=tampon.find(';');
    sentence->replace(nb+offset.size(),nb2,value);
}
void RechercheInfo::searchCutRight(std::string* sentence,std::string sentenceToSearch,bool cutSentenceToSearch)
{
   unsigned int nb=sentence->find(sentenceToSearch);
   if(nb>sentence->size())
   {
       sentence->replace(0,sentence->size(),"");
       return;
   }
   nb+=(cutSentenceToSearch)?0:sentenceToSearch.size();
   sentence->replace(nb,sentence->size(),"");
}

