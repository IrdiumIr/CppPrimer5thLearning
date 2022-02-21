//Ex8.11  本节的程序在外层while循环中定义了istringstream对象。如果record对象定义在循环之外，需要进行怎样的修改？
//        重写程序，将record的定义移到while循环之外，验证你设想的修改方法是否正确。

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::cin;
using std::istringstream;

class PersonInfo
{
    public:
        string name;
        vector<string> phones;
};

int main()
{
    string line, word;
    vector<PersonInfo> people;

    istringstream record;//外部定义 record

    while(getline(cin, line))
    {
        PersonInfo info;
        //istringstream record(line);原循环内部定义
        record.str(line);//内部绑定到line
        record >> info.name;

        while (record >> word)
        {
            info.phones.push_back(word);
        }

        people.push_back(info);
    }    
}