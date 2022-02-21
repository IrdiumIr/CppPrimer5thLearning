//Ex6.23  参考本节介绍的几个print函数，根据理解编写你自己的版本。依次调用每个函数使其输入下面定义的i和j:
//        int i = 0, j[2] = { 0, 1 };

#include <iostream>

using std::begin;
using std::cout;
using std::end;
using std::endl;

void print(const int *p)
{
    cout << *p << endl;
}

void print(const int *beg, const int *end)
{
    while (beg != end)
    {
        cout << *beg++ << ' ';
    }
    cout << endl;
}

int main()
{
    int i = 0, j[2] = {0, 1};
    print(&i);
    print(begin(j), end(j));
    return 0;
}
