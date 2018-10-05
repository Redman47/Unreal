#include "books.h"
#include <sstream>
#include <QList>

std::ostream &operator<<(std::ostream &stream, Books& objBook)
{
    if(objBook.m_switch)
    {
        stream << "Book Number:" << objBook.getBookNumber()<<
                  " Count Book:" << objBook.getCountBook()<<
                  " Book Name:" << objBook.getBookName()<<
                  " AuthorBook:" << objBook.getAuthorBook()<<
                  " Genre:" << objBook.getGenre()<<
                  " Year of writing:"<< objBook.getYearOfWriting()<<
                  '\n';
    }
    else{
        stream << objBook.getBookNumber()<<
                  ';' << objBook.getCountBook()<<
                  ';' << objBook.getBookName()<<
                  ';' << objBook.getAuthorBook()<<
                  ';' << objBook.getGenre()<<
                  ';' << objBook.getYearOfWriting() <<'\n';
        return stream;
    }
    return stream;
}

std::istream &operator>>(std::istream &stream, Books& objBook)
{
    std::string sTmp;
    std::getline(stream,sTmp);
    std::stringstream ss(sTmp);
    std::string token;
    QList<std::string> sListToken;
    while(std::getline(ss, token, ';'))
    {
        sListToken.push_back(token);
    }

    if(sListToken.length() == 6)
    {
        objBook.setBookNumber(atoi(sListToken.takeFirst().c_str()));
        objBook.setCountBook(atoi(sListToken.takeFirst().c_str()));
        objBook.setBookName(sListToken.takeFirst());
        objBook.setAuthorBook(sListToken.takeFirst());
        objBook.setGenre(sListToken.takeFirst());
        objBook.setYearOfWriting(atoi(sListToken.takeFirst().c_str()));
    }

    return stream;
}

Books::Books():countBook(0),bookNumber(0),yearOfWriting(0000),m_switch(false)
{}

void Books::setBookNumber(const int value)
{
    bookNumber = value;
}

void Books::setCountBook(const int value)
{
    countBook = value;
}

void Books::setAuthorBook(const std::string sStr)
{
    sAuthorBook = sStr;
}

void Books::setBookName(const std::string sStr)
{
    sBookName = sStr;
}

void Books::setGenre(const std::string sStr)
{
    sGenre = sStr;
}

void Books::setYearOfWriting(const int value)
{
    yearOfWriting = value;
}

int Books::getBookNumber()
{
    return bookNumber;
}

int Books::getCountBook()
{
    return countBook;
}

std::string Books::getAuthorBook()
{
    return sAuthorBook;
}

std::string Books::getBookName()
{
    return sBookName;
}

std::string Books::getGenre()
{
    return sGenre;
}

int Books::getYearOfWriting()
{
    return yearOfWriting;
}


