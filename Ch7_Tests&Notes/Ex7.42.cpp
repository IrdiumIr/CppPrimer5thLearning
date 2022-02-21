//Ex7.42  对于你在练习7.40中编写的类，确定哪些构造函数可以使用委托。如果可以的话，编写委托构造函数。
//        如果不可以，从抽象概念列表中重新选择一个你认为可以使用委托构造函数的，为挑选出的这个概念编写类定义。

#include <iostream>
#include <string>
using std::cin;
using std::istream;
using std::string;

class Book {
public:
    using uns = unsigned;
    Book(uns isb, const string &nam, const string &wri, const string pub) 
        : isbn(isb), name(nam), writer(wri), publisher(pub) { }
    //委托
    Book() : Book(0, " ", " ", " ") {}
    Book(uns isb) : Book(isb, " ", " ", " ") {}
    Book(istream &in) : Book() { in >> isbn >> name >> writer >> publisher; }
    
private:
    uns isbn;
    string name;
    string writer;
    string publisher;
};