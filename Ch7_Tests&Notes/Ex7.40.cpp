//Ex7.40  从下面的抽象概念中选择一个，思考需要哪些数据成员，提供一组合理的构造函数.
//        (a) Book; (b) Data; (c) Employee; (d) Vehicle; (e) Object; (f) Tree
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
    Book(istream &in = cin) 
    { 
        in >> isbn >> name >> writer >> publisher;
    }
private:
    uns isbn;
    string name;
    string writer;
    string publisher;
};