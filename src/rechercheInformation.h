#ifndef rechercheInfo
#define rechercheInfo
#include <iostream>
#include <string>

class RechercheInfo
{
    public:

        static void searchCutLeft(std::string* sentence,std::string sentenceToSearch,bool cutSentenceToSearch=true ) {
               unsigned int nb=sentence->find(sentenceToSearch);
               if(nb>sentence->size())
               {

                   sentence->replace(0,sentence->size(),"");
                   return;
               }
               nb+=(cutSentenceToSearch)?sentenceToSearch.size():0;
               sentence->replace(0,nb,"");
        }


        static void searchCutRight(std::string* sentence,std::string sentenceToSearch , bool cutSentenceToSearch = true ) {
           unsigned int nb = sentence->find(sentenceToSearch);
           if(nb > sentence->size())
           {
               sentence->replace(0,sentence->size(),"");
               return;
           }
           nb += (cutSentenceToSearch)?0:sentenceToSearch.size();
           sentence->replace(nb,sentence->size(),"");
        }


};


#endif
