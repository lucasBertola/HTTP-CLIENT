#ifndef rechercheInfo
#define rechercheInfo
#include <iostream>

class RechercheInfo
{
    public:

        static void searchCutLeft(std::string* sentence,std::string sentenceToSearch,bool cutSentenceToSearch=true );
        static void searchCutRight(std::string* sentence,std::string sentenceToSearch,bool cutSentenceToSearch=true );
        static void remplace(std::string* sentence,std::string variable,std::string value);
    private:


};


#endif
