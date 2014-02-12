#include "excel.h"
#include <fstream>

CsvManager::CsvManager(std::string fileName){

    this->fichier= new ofstream (fileName.c_str(), ios::out | ios::trunc);
}
void CsvManager::addLigne(std::string ville,std::string adresse) {
    char changerCase = ';';
    (*(this->fichier))<<ville<<changerCase<<changerCase<<changerCase<<adresse<<std::endl;
}
CsvManager::~CsvManager() {
    this->fichier->close();
    delete fichier;
}
