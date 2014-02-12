#ifndef excelh
#define excelh

#include <iostream>

using namespace std;

class  CsvManager {
    public:
    CsvManager(std::string fileName);
    ~CsvManager();
    void addLigne(std::string ville,std::string adresse);
    private:
        ofstream* fichier;
};
#endif
