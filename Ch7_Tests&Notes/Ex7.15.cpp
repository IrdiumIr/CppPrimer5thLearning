//Ex7.15  为你的Person类添加正确的构造函数。

#include <iostream>
#include <string>
using std::istream;
using std::ostream;
using std::string;

struct Person
{
    Person() = default;
    Person(const string &cname, const string &caddress) : name(cname), address(caddress) {}
    Person(istream &is) { read(is, *this); }

    string name;
    string address;

    string getName() const { return name; }
    string getAddress() const { return address; }
};
// 7.9 copy
istream &read(istream &is, Person &person)
{
    is >> person.name >> person.address;
    return is;
}

ostream &print(ostream &os, const Person &person)
{
    os << person.getName() << " " << person.getAddress();
    return os;
}