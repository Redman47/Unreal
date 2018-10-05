#pragma once
#include <string>
#include<iostream>
#include <ostream>

class Books
{
public:
    Books();
    bool m_switch;

    //Сетеры
    void setBookNumber(const int value);
    void setCountBook(const int value);
    void setAuthorBook(const std::string sStr);
    void setBookName(const std::string sStr);
    void setGenre(const std::string sStr);
    void setYearOfWriting(const int value);

    //Гетеры
    int getBookNumber();
    int getCountBook();
    std::string getAuthorBook();
    std::string getBookName();
    std::string getGenre();
    int getYearOfWriting();

   friend std::ostream &operator<<(std::ostream &, Books&);
   friend std::istream &operator>>(std::istream&, Books&);


private:
    int bookNumber;
    int countBook;
    int yearOfWriting;
    std::string sAuthorBook;
    std::string sBookName;
    std::string sGenre;

};

