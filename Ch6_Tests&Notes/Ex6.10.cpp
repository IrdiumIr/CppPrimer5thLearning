//Ex6.10  编写一个函数，使用指针形参交换两个整数的值。在代码中调用该函数并输出交换后的结果，以此验证函数的正确性。

#include<iostream>
using std::cout;
using std::endl;

int swap(int *p1, int *p2)
{
    int tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
    return 0;
}

int main()
{
    int i1 = 0, i2 = 1;
    cout << "i1 = " << i1 << ", i2 = " << i2 << endl;
    swap(&i1, &i2);
    cout << "i1 = " << i1 << ", i2 = " << i2 << endl;
    return 0;
}