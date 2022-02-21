//Ex8.13  重写本节的电话号码程序，从一个命名文件而非cin读取数据。

#include <iostream>
#include <sstream>
#include <fstream>//从一个命名文件而非cin读取数据
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::ostringstream;
using std::string;
using std::vector;

class PersonInfo {
public:
    string name;
    vector<string> phones;
};

int main()
{
    ifstream ifs("fileName");

    string line, phoneNumber;
    vector<PersonInfo> people;
    istringstream record;

    while (getline(ifs, line))
    {
        record.str(line);
        PersonInfo info;//每行单独的对象info，分开处理1个name和？个phones
        record >> info.name;//save name

        while (record >> phoneNumber)
        {
            info.phones.push_back(phoneNumber);//save phones
        }//处理完毕单个info
        people.push_back(info);//存入people
    }

    for (const auto &entry : people)
    {
        ostringstream formatted, unformatted;
        
        for (const auto &phonenumber : entry.phones)
        {
            if (!valid(phonenumber))//P289
            {
                unformatted << phonenumber << " ";
            }
            else
            {
                formatted << format(phonenumber) << " ";//P289
            }
        }

        if (unformatted.str().empty())
        {
            cout << entry.name << " " << formatted.str() << endl;
        }
        else
        {
            cout << "error: " << entry.name << " " << unformatted.str() << endl;
        }
    }

    return 0;
}