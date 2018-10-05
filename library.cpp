#include "library.h"
#include "books.h"
#include "visitor.h"
#include <QDate>

#include <iomanip>

Library::Library()
{
}

void Library::Init()
{
    int i{ 1 };
    std::cout << std::setw(50) << "!Library!"<<std::endl;
    std::cout << "Select the action do you want"<<std::endl;
    std::cout << '<' << i << '>' << "Add book" << std::endl;
    std::cout << '<' << ++i << '>' << "Add reader" << std::endl;
    std::cout << '<' << ++i << '>' << "Take book" << std::endl;
    std::cout << '<' << ++i << '>' << "Return book" << std::endl;
    std::cout << '<' << ++i << '>' << " Show books that are in the library" << std::endl;
    std::cout << '<' << ++i << '>' << " Show visitor that are in the library" << std::endl;
    std::cout<< '<' << ++i << '>' <<"Exit"<<'\n';
}

void Library::InitVarible()
{
    setReaderNumberOfFile();
    setBookNumberOfFile();
    m_keyMap = WorkWithFile::loadAccountingOfFile("Accounting");
}

void Library::addVisitor()
{
    int i{0};
    do
    {
        std::cout << std::setw(50) << "!Add Reader!"<<std::endl;
        std::cout<< std::endl<<'<' << ++i << '>' << "Back " << std::endl;
        std::cout << '<' << ++i << '>' << " Add Reader" << std::endl;
        std::cout<< "Enter the number of steps ";
        std::cin>>i;
        switch (i) {
        case 1:{
            i=1;
            break;
        }
        case 2:{
            std::string sReaderNumber,sSurname,sName,sAddress,sNumberPhone;
            std::cout << "Input Reader Number: ";
            std::getline(std::cin, sReaderNumber);
            std::getline(std::cin, sReaderNumber);
            int readerNumber = atoi(sReaderNumber.c_str());
            if(isdigit(readerNumber) || readerNumber == 0)
            {
                std::cout <<"Error input";
                i = 0;
                break;
            }
            std::cout << "Input Surname: ";
            std::getline(std::cin, sSurname);
            std::cout <<"Input  Name: ";
            std::getline(std::cin, sName);
            std::cout <<"Input Address: ";
            std::getline(std::cin, sAddress);
            std::cout <<"Input Nuber Phone: ";
            std::getline(std::cin, sNumberPhone);
            std::cout<<"Save Reader?"<<'\n'<<"Input <1>-yes or <2>-no "<<std::endl;
            std::cin>>i;
            if(i==1)
            {
                if(validateReaderNumber(readerNumber)){
                    Visitor visitor;
                    visitor.setReaderNumber(readerNumber);
                    visitor.setSurname(sSurname);
                    visitor.setName(sName);
                    visitor.setAddress(sAddress);
                    visitor.setNumberPhone(sNumberPhone);
                    WorkWithFile file;
                    file.addObjInFile(visitor,"Visitors");
                    i=0;
                }
                else {
                    std::cout << "A reader with such numbers already exists \n";
                }

            }
            else i = 0;
        }
        default: i =0;
        }
    }while(i!=1);
    start();
}

void Library::addBook()
{
    int i{0};
    do
    {
        std::cout << std::setw(50) << "!Add Book!"<<std::endl;
        std::cout<< std::endl<<'<' << ++i << '>' << "Back " << std::endl;
        std::cout << '<' << ++i << '>' << " Add Book" << std::endl;
        std::cout<< "Enter the number of steps ";
        std::cin>>i;
        switch (i) {
        case 1:{
            i=1;
            break;
        }
        case 2:{
            std::string sBookNumber, sCountBook, sYearOfWriting, sAuthorBook, sBookName, sGenre;

            std::cout << "Input Book Number: ";
            std::getline(std::cin, sBookNumber);
            std::getline(std::cin, sBookNumber);
            std::cout << "Input Count Book: ";
            std::getline(std::cin, sCountBook);
            std::cout <<"Input  Book Name: ";
            std::getline(std::cin, sBookName);
            std::cout <<"Input Author Book: ";
            std::getline(std::cin, sAuthorBook);
            std::cout <<"Input Genre: ";
            std::getline(std::cin, sGenre);
            std::cout <<"Input Year Of Writing: ";
            std::getline(std::cin, sYearOfWriting);
            int bookNumber = atoi(sBookNumber.c_str());
            int countBook = atoi(sCountBook.c_str());
            int yearOfWriting = atoi(sYearOfWriting.c_str());
            if(isdigit(bookNumber) || bookNumber == 0 || countBook == 0 || yearOfWriting == 0)
            {
                std::cout <<"Error input\n";
                i = 0;
                break;
            }
            else if(QDate::currentDate().year() < yearOfWriting)
            {
                std::cout <<"A year can not be more current!\n";
                i = 0;
                break;
            }
            std::cout<<"Save Book?"<<'\n'<<"Input <1>-yes or <2>-no "<<std::endl;
            std::cin>>i;
            if(i==1)
            {
                if(validateBookNumber(bookNumber)){
                    Books book;
                    book.setBookNumber(bookNumber);
                    book.setCountBook(countBook);
                    book.setBookName(sBookName);
                    book.setAuthorBook(sAuthorBook);
                    book.setGenre(sGenre);
                    book.setYearOfWriting(yearOfWriting);
                    WorkWithFile file;
                    file.addObjInFile(book,"Books");
                    i=0;
                }
                else{
                    std::cout << "A reader with such numbers already exists \n";
                }
            }
            else i = 0;
        }
        default: i =0;
        }
    }while(i!=1);
    start();
}

void Library::takeBook()
{
    InitVarible();
    std::cout << "Input Reader Number: ";
    std::string sTmpstr;
    std::getline(std::cin,sTmpstr);
    std::getline(std::cin,sTmpstr);
    const int readerNumber = atoi(sTmpstr.c_str());
    if (findReaderNumberInData(readerNumber)) {
        constIteratorBook it = m_dataBooks.cbegin();
        for (int i =1; it != m_dataBooks.cend(); ++it, ++i) {
            Books book = *it;
            book.m_switch = true;
            std::cout <<"<" <<i <<">" << book;
        }
        std::cout << "Select Book:";
        int selectBook;
        std::cin >>  selectBook;
        if(selectBook > m_dataBooks.size() || selectBook < 0)
        {
            std::cout <<"Dont correct number";
            return;
        }
        else {
            --selectBook;
            Books book = m_dataBooks.at(selectBook);
            int countBook = book.getCountBook();
            if(countBook > 0)
            {
                --countBook;
                book.setCountBook(countBook);
                m_dataBooks[selectBook] = book;
                WorkWithFile::saveDataInFile(m_dataBooks,"Books");
                writeBookOnReader(readerNumber,selectBook);
            }
            else
            {
                std::cout << "Books dont have!";
                return;
            }
        }
    }
    else
    {
        std::cout <<"The Wrong Nuber!!!"<<'\n' << "Do you want create reader cart? \n";
        std::cout <<"<1>Yes " << "<2>No \n";
        int step = 0;
        std::cin >> step;
        if(step == 1)
        {
            addVisitor();
        }
        else
            return;
    }
}

void Library::returnBook()
{
    InitVarible();
    std::cout << "Input Reader Number: ";
    std::string sTmpstr;
    std::getline(std::cin,sTmpstr);
    std::getline(std::cin,sTmpstr);
    int readerNumber = atoi(sTmpstr.c_str());
    if (findReaderNumberInData(readerNumber))
    {
        int step = 0;
        do{
            std::multimap<int,int> mKeyReaderAndBook = findReaderBook(readerNumber);
            if(mKeyReaderAndBook.size() > 0)
            {
                std::cout<< "You owe:\n";
                int count = 1;
                for(auto it = mKeyReaderAndBook.begin(); it!=mKeyReaderAndBook.end(); ++it)
                {
                    std::cout <<'<' << it->first<<'>' << "Number of the book:" <<it->second << '\n';
                    ++count;
                }
                std::cout<< "To hand over the book with number\n";
                int step = 0;
                std::cin >> step;
                refundReaderBook(mKeyReaderAndBook.find(step)->second, readerNumber);
            }
            else
            {
                std::cout << "You do not have any books. " << "Would you like to take?\n"
                          << "<1>Yes " << "<2>No \n" ;
                int step = 0;
                std::cin >> step;
                if(step == 1)
                {
                    takeBook();
                }
                else
                    return;
            }
            std::cout <<"Return more?\n" << "<1>Yes " << "<2>No \n" ;
            std::cin >> step;
        }while(step!=2);
    }
    else
    {
        std::cout <<"The Wrong Nuber!!!"<<'\n' << "Do you want create reader cart? \n";
        std::cout <<"<1>Yes " << "<2>No \n";
        int step = 0;
        std::cin >> step;
        if(step == 1)
        {
            addVisitor();
        }
        else
            return;
    }
}

bool Library::findReaderNumberInData(const int readerNumber)
{
    constIteratorVisitor it = m_dataVisitor.begin();
    for(; it != m_dataVisitor.end(); ++it)
    {
        Visitor visitor = *it;
        if(visitor.getReaderNumber() == readerNumber){
            visitor.m_switch = true;
            std::cout << visitor;
            return true;
        }
    }
    return false;

}

void Library::setReaderNumberOfFile()
{
    WorkWithFile file;
    m_dataVisitor = file.getVectorReadersOfFile("Visitors");
    constIteratorVisitor it = m_dataVisitor.begin();
    for(;it != m_dataVisitor.end(); ++it)
    {
        Visitor visitor = *it;
        m_visitorsNumber.push_back(visitor.getReaderNumber());
    }
}

void Library::setBookNumberOfFile()
{
    WorkWithFile file;
    m_dataBooks = file.getVectorBooksOfFile("Books");
    constIteratorBook it = m_dataBooks.begin();
    for(;it != m_dataBooks.end(); ++it)
    {
        Books book = *it;
        m_booksNumber.push_back(book.getBookNumber());
    }
}

bool Library::validateReaderNumber(const int readerNumber)
{
    constIteratorInt it = m_visitorsNumber.begin();

    for(;it != m_visitorsNumber.end();++it) {
        if(*it == readerNumber) return false;
    }
    return true;
}

bool Library::validateBookNumber(const int bookNumber)
{
    constIteratorInt it = m_booksNumber.begin();

    for(;it != m_booksNumber.end();++it) {
        if(*it == bookNumber) return false;
    }
    return true;
}

void Library::writeBookOnReader(const int readreNubmer, const int selectBook)
{
    Books book = m_dataBooks.at(selectBook-1);
    m_keyMap.insert(std::make_pair(readreNubmer, book.getBookNumber()));
    WorkWithFile file;
    if(file.saveAccountingInFile(m_keyMap,"Accounting"))
        std::cout << "Success! \n";
    else
        std::cout << "Erro open or create files";

}

std::multimap<int,int> Library::findReaderBook(const int readerNumber)
{
    std::multimap<int,int> mTmp;
    int i =0;
    for(auto it : m_keyMap)
    {
        if(it.first == readerNumber)
            mTmp.insert(std::make_pair(i,it.second));
        ++i;
    }
    return mTmp;
}

void Library::refundReaderBook(const int bookNumber, const int readerNumber)
{
    for(auto it = m_keyMap.begin(); it != m_keyMap.end();){
        if(it->second == bookNumber && it->first == readerNumber)
        {
           it = m_keyMap.erase(it);
           for(int i = 0; i < m_dataBooks.size();++i)
           {
               Books book = m_dataBooks.at(i);
               if(book.getBookNumber() == bookNumber)
               {
                   book.setCountBook(book.getCountBook() + 1);
                   m_dataBooks[i] = book;
                   WorkWithFile::saveDataInFile(m_dataBooks, "Books");
                   break;
               }

           }
           break;
        }
        else
            ++it;
    }
    WorkWithFile::saveAccountingInFile(m_keyMap,"Accounting");
    std::cout <<"Success! \n";
}

void Library::start()
{
    unsigned int step{0};
    do
    {
        Init();
        std::cout<< "Enter the number of steps ";
        std::cin>> step;
        switch (step) {
        case 1:
            addBook();
            break;
        case 2:
            addVisitor();
            break;
        case 3:
            takeBook();
            break;
        case 4:
            returnBook();
            break;
        case 5:
        {
            Books book;
            book.m_switch = true;
            showAllInfoOfFile(book, "Books");
            break;
        }
        case 6:
        {
            Visitor visitor;
            visitor.m_switch = true;
            showAllInfoOfFile(visitor, "Visitors");
            break;
        }
        case 7:
            break;
        }

    }while (step != 7);

}
