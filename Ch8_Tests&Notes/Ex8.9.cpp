//Ex8.9   使用你为8.1.2节第一个练习所编写的函数打印一个istringstream对象的内容。

#include <iostream>
#include <sstream>//add
using std::cout;
using std::endl;
using std::istream;
using std::istringstream;
using std::string;

istream& fun(istream& is)
{
    string data;
    while (is >> data)
    {
        cout << data << endl;
    }
    //复位
    is.clear();
    return is;
}

int main()
{
    istringstream iss("test");
    fun(iss);
    return 0;
}

