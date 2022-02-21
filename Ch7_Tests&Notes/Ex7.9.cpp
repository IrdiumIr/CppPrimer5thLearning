//Ex7.9  对于7.1.2节练习中代码，添加读取和打印Person对象的操作。

#include <string>
#include <iostream> // 需要读取和打印
using std::istream;
using std::ostream;
using std::string;

struct Person
{
    string name;
    string address;

    string getName() const { return name; }
    string getAddress() const { return address; }
};

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