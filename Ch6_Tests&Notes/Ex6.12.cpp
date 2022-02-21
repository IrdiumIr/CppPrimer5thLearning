//Ex6.12  改写6.2.1节练习中的程序，使其引用而非指针交换两个整数的值。你觉得哪种方法更易于使用呢？为什么？

#include<iostream>
using std::cout;
using std::endl;

void swap(int &p1, int &p2)
{
    int tmp;
    tmp = p1;
    p1 = p2;
    p2 = tmp;
}

int main()
{
    int i1 = 0, i2 = 1;
    cout << "i1 = " << i1 << ", i2 = " << i2 << endl;
    swap(i1, i2);
    cout << "i1 = " << i1 << ", i2 = " << i2 << endl;
    return 0;
}