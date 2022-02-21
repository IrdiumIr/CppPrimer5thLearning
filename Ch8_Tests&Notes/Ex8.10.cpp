//Ex8.10  编写程序，将来自一个文件中的行保存在一个vector中。然后使用一个istringstream从vector读取数据元素，每次读取一个单词。

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

int main()
{
    ifstream ifs("fileName");

    string str;
    vector<string> vecStr;//line vector
    while (getline(ifs, str))
    {
        vecStr.push_back(str);
    }

    for (auto &s : vecStr)
    {
        istringstream iss(s);//iss bongding to each vector element

        string word;
        while (iss >> word)
        {
            cout << word << endl;
        }
    }
    return 0;
}

