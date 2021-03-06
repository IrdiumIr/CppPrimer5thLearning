//Ex8.1   编写函数，接受一个istream&参数，返回值类型也是istream&。此函数须从给定流中读取数据，直至遇到文件结束标识时停止。
//        它将读取的数据打印在标准输出上。完成这些操作后，在返回流之前，对流进行复位，使其处于有效状态。

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