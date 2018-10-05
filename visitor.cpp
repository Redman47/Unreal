#include "visitor.h"
#include <QList>
#include <sstream>

std::ostream &operator<<(std::ostream &stream, Visitor& objVisitor)
{
    if(objVisitor.m_switch)
    {
        stream<<"Redader Number:"<<
                objVisitor.getReaderNumber()<<
                " Name:"<<
                objVisitor.getName()<<
                " Surname:"<<
                objVisitor.getSurname()<<
                " Addres:"<<
                objVisitor.getAddres()<<
                " Phone: "<<
                objVisitor.getNumberPhone() << '\n';
    }
    else
    {
        stream<<objVisitor.getReaderNumber()<<
                ';' <<objVisitor.getName()<<
                ';' << objVisitor.getSurname()<<
                ';' << objVisitor.getAddres()<<
                ';' << objVisitor.getNumberPhone()<<
                '\n';
        return stream;
    }

    return stream;
}

std::istream &operator>>(std::istream &stream, Visitor& objVisitor)
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

    if(sListToken.length() == 5)
    {
        objVisitor.setReaderNumber(atoi(sListToken.takeFirst().c_str()));
        objVisitor.setName(sListToken.takeFirst());
        objVisitor.setSurname(sListToken.takeFirst());
        objVisitor.setAddress(sListToken.takeFirst());
        objVisitor.setNumberPhone(sListToken.takeFirst());
    }

    return stream;
}

Visitor::Visitor():readerNumber(0),m_switch(false)
{}


std::string Visitor::getSurname()
{
    return sSurname;
}

void Visitor::setSurname(const std::string sStr)
{
    sSurname = sStr;
}

std::string Visitor::getName()
{
    return sName;
}

void Visitor::setName(const std::string sStr)
{
    sName = sStr;
}

std::string Visitor::getAddres()
{
    return sAddress;
}

void Visitor::setAddress(const std::string sStr)
{
    sAddress = sStr;
}

std::string Visitor::getNumberPhone()
{
    return sNumberPhone;
}

void Visitor::setNumberPhone(const std::string sStr)
{
    sNumberPhone = sStr;
}

int Visitor::getReaderNumber()
{
    return readerNumber;
}

void Visitor::setReaderNumber(const int value)
{
    readerNumber = value;
}

