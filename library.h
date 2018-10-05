#pragma once
#include "workwithfile.h"

#include <iostream>
#include <string>
#include <map>

using constIteratorBook = std::vector<Books>::const_iterator;
using constIteratorVisitor = std::vector<Visitor>::const_iterator;
using constIteratorInt = std::vector<int>::const_iterator;


class Library
{
public:
    Library();
    void start();
protected:
    std::vector<Books>    m_dataBooks;
    std::vector<Visitor> m_dataVisitor;
    std::vector<int> m_visitorsNumber;
    std::vector<int> m_booksNumber;
    std::multimap<int,int> m_keyMap;

private:
    void Init();
    void InitVarible();
    void addVisitor();
    void addBook();
    void takeBook();
    void returnBook();
    template<class T> void showAllInfoOfFile(T& obj,const std::string nameFile);
    bool findReaderNumberInData(const int readerNumber);
    void setReaderNumberOfFile();
    void setBookNumberOfFile();
    bool validateReaderNumber(const int readerNumber);
    bool validateBookNumber(const int bookNumber);
    void writeBookOnReader(const int readreNubmer, const int selectBook);
    std::multimap<int,int> findReaderBook(const int readerNumber);
    void refundReaderBook(const int bookNumber,const int readerNumber);

};

template<class T>
void Library::showAllInfoOfFile(T& obj,const std::string nameFile){
    WorkWithFile file;
    file.loadAllDataOfFile(obj,nameFile);
}
