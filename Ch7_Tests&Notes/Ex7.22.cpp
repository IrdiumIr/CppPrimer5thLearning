//Ex7.22  修改你的Person类使其隐藏实现的细节。

#include <iostream>
#include <string>
using std::istream;
using std::ostream;
using std::string;

struct Person
{
    friend istream &read(istream &is, Person &person);
    friend ostream &print(ostream &os, const Person &person);

public:
    Person() = default;
    Person(const string &cname, const string &caddress) : name(cname), address(caddress) {}
    Person(istream &is) { read(is, *this); }

private:
    string name;
    string address;

public:
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