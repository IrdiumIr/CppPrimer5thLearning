//Ex6.25&26  编写一个main函数，令其接受两个实参。把实参的内容连接成一个string对象并输出出来。
//           编写一个程序，使其接受本节所示的选项；输出传递给main函数的实参内容。

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
    string str;
    for (auto i = 1; i != argc; ++i)
        str += argv[i];
    cout << str << endl;
    return 0;
}
