//Ex6.22  编写一个函数，令其交换两个int指针。

#include <iostream>

using std::cout;
using std::endl;

void swap(int *(&p1), int *(&p2))
{
    int *tmp;
    tmp = p1;
    p1 = p2;
    p2 = tmp;
}

int main()
{
    int i1 = 1, i2 = 2;
    int *p1 = &i1, *p2 = &i2;
    cout << "p1 = " << p1 << "; p2 = " << p2 << endl;
    swap(p1, p2);
    cout << "p1 = " << p1 << "; p2 = " << p2 << endl;
    return 0;
}
