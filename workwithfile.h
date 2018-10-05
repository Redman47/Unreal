#pragma once
#include "books.h"
#include "visitor.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

class WorkWithFile
{
public:
    WorkWithFile();

    template<class T> void addObjInFile(T& obj,const std::string fileName);
    template<class T> void loadInfoOfFile(T& obj,const std::string fileName);
    template<class T> void loadAllDataOfFile(T& obj,const std::string fileName);
    std::vector<Visitor> getVectorReadersOfFile(const std::string fileName);
    static bool saveAccountingInFile(const std::multimap<int,int>&mapKeyNumber, const std::string fileName);
    static std::multimap<int,int> loadAccountingOfFile(const std::string fileName);
    static bool saveDataInFile(const std::vector<Books>& dataBooks, const std::string fileName);
    std::vector<Books> getVectorBooksOfFile(const std::string fileName);
};

template<typename T>
void WorkWithFile::addObjInFile(T& obj, const std::string fileName)
{
    std::string path = fileName;
    path+= ".csv";
    std::ofstream file(path,std::ios_base::app);
    if(file.is_open())
    {
        file << obj;
        file.close();
        std::cout << "Success! \n";
    }
    else {
        std::cout << "Erro open or create files";
    }
}

template<class T>
void WorkWithFile::loadInfoOfFile(T& obj,const std::string fileName)
{
    std::string path = fileName;
    path+= ".csv";
    std::ifstream file(path,std::ios_base::in);
    if(file.is_open())
    {
        file >> obj;
        file.close();
        std::cout << "Success! \n";
    }
    else {
        std::cout << "Erro open or read files";
    }
}

template<class T>
void WorkWithFile::loadAllDataOfFile(T& obj,const std::string fileName)
{
    std::string path = fileName;
    path+= ".csv";
    std::ifstream file(path,std::ios_base::in);
    if(file.is_open())
    {
        int count {0};
        while (file >> obj) {
            std::cout << '<' <<++count << '>' << obj;
        }
    }
    else std::cout<< "Erro open file";
}



