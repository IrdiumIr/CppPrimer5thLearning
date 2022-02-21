//Ex8.5   重写上面的程序，将每个单词作为一个独立的元素进行存储。

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
        //changes
        while (ifs >> str1)
        {
            vec.push_back(str1);
        }
    }
}