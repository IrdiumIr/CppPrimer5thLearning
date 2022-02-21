//Ex8.2   测试函数，调用参数为cin。

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::string;

istream& fun(istream& is)
{
    string data;
    while (cin >> data)
    {
        cout << data << endl;
    }
    //复位
    is.clear();
    return is;
}
//test code
int main()
{
    fun(cin);
    return 0;
}