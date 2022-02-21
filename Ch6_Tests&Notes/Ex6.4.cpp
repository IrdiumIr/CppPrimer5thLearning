//Ex6.4  编写一个与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。在main函数中调用该函数。

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

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
