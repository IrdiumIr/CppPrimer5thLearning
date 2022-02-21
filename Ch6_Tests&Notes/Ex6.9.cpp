//Ex6.9  编写你自己的fact.cc和factMain.cc，这两个文件都应该包含上一小节的练习中编写的Chapter6.h头文件。
//       通过这些文件，理解你的编译器是如何支持分离式编译的。

//fact.cc
#include "Chapter6.h"
#include <iostream>

int fact(int val)
{
    int ret = 1;
    while (val > 1)
    {
        ret *= val;
        --val;
    }
    return ret;
}

//factMain.cc
#include "Chapter6.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n;
    cout << "Input number N: ";
    while (cin >> n)
    {
        cout << "Factor of N is: " << fact(n) << endl;
        cout << "Input number N: ";
    }
    return 0;
}

//     编译： g++ factMain.cc fact.cc -o main