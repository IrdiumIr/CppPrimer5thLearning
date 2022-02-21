//Ex6.51  编写函数f的4版本，令其各输出一条可以区分的消息。验证上一个练习的答案，如果你的回答错了，反复研究本节内容直到你弄清自己错在何处。

#include <iostream>

using std::cout;
using std::endl;

void f() { cout << "f()" << endl; }

void f(int) { cout << "f(int)" << endl; }

void f(int, int) { cout << "f(int, int)" << endl; }

void f(double, double = 3.14) { cout << "f(double, double = 3.14)" << endl; }

int main()
{
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}