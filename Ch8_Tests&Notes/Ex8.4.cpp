//Ex8.4   编写函数，以读模式打开一个文件，将其内容读入到一个string的vector中，将每一行作为一个独立的元素存于vector中。

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using std::ifstream;
using std::string;
using std::vector;

void read(const string &name, vector<string> vec)
{
    ifstream ifs(name);//bonding ifs-filename
    if (ifs)//test 
    {
        string str1;
        while (getline(ifs, str1))
        {
            vec.push_back(str1);
        }
    }
}