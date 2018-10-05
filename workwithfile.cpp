#include "workwithfile.h"
#include <QDebug>
#include <sstream>

WorkWithFile::WorkWithFile()
{
    setlocale(LC_ALL, "Russian");
}

std::vector<Visitor> WorkWithFile::getVectorReadersOfFile(const std::string fileName)
{
    std::string path = fileName;
    path+= ".csv";
    std::ifstream file(path,std::ios_base::in | std::ios_base::binary);
    std::vector<Visitor> vectorVisitor;
    Visitor visitor;
    if(file.is_open())
    {
        while(file >> visitor)  vectorVisitor.push_back(visitor);
        return vectorVisitor;
    }
    else {
        qDebug()<< "Erro open or file whith readers empty";
    }
    return vectorVisitor;
}

bool WorkWithFile::saveAccountingInFile(const std::multimap<int, int> & mapKeyNumber, const std::string fileName)
{
    std::string path = fileName;
    path+= ".csv";
    std::ofstream file(path,std::ios_base::trunc | std::ios_base::binary);
    if(file.is_open())
    {
        for(auto value : mapKeyNumber){
            file << value.first << ";" << value.second << '\n';
        }
        file.close();
        return true;
    }
    else
        return false;
    return false;
}

std::multimap<int, int> WorkWithFile::loadAccountingOfFile(const std::string fileName)
{
    std::string path = fileName;
    path+= ".csv";
    std::ifstream file(path,std::ios_base::in | std::ios_base::binary);
    std::multimap<int,int> mapKeyNumber;
    if(file.is_open())
    {
        std::string sTmpStr;
        while(std::getline(file, sTmpStr))
        {
            std::string token;
            QList<int> listToken;
            std::stringstream sstream(sTmpStr);
            while(std::getline(sstream, token, ';'))
            {
                listToken.push_back(atoi(token.c_str()));
            }
            if(listToken.length() != 2)
            {
                std::cout<< "Error file format";
                break;
            }
            else
            {
                mapKeyNumber.insert(std::make_pair(listToken.takeFirst(),listToken.takeLast()));
            }
        }
        return mapKeyNumber;
    }
    else {
        qDebug()<< "Erro open or file whith key empty";
    }
    return mapKeyNumber;
}

bool WorkWithFile::saveDataInFile(const std::vector<Books> &dataBooks, const std::string fileName)
{
    std::string path = fileName;
    path+= ".csv";
    std::ofstream file(path,std::ios_base::trunc | std::ios_base::binary);
    if(file.is_open())
    {
        for(auto value : dataBooks){
            file << value;
        }
        file.close();
        return true;
    }
    else
        return false;
    return false;
}

std::vector<Books> WorkWithFile::getVectorBooksOfFile(const std::string fileName)
{
    std::string path = fileName;
    path+= ".csv";
    std::ifstream file(path,std::ios_base::in | std::ios_base::binary);
    std::vector<Books> vectorBooks;
    Books book;
    if(file.is_open())
    {
        while(file >> book)  vectorBooks.push_back(book);
        return vectorBooks;
    }
    else {
        qDebug()<< "Erro open or file whith books empty";
    }
    return vectorBooks;
}

