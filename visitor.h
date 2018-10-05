#pragma once
#include <iostream>
#include <string>
#include <ostream>
class Visitor
{
public:
    Visitor();
    bool m_switch;
    //Сетеры
    void setReaderNumber(const int value);
    void setSurname(const std::string sStr);
    void setName(const std::string sStr);
    void setAddress(const std::string sStr);
    void setNumberPhone(const std::string sStr);

    //Гетеры
    int getReaderNumber();
    std::string getSurname();
    std::string getName();
    std::string getAddres();
    std::string getNumberPhone();

private:
    friend std::istream &operator>>(std::istream &stream, Visitor& objBook);
    friend std::ostream& operator<<(std::ostream &, Visitor&);

    int readerNumber;
    std::string sSurname;
    std::string sName;
    std::string sAddress;
    std::string sNumberPhone;

};


