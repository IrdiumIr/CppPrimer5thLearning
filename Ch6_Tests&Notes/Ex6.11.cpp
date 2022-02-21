//Ex6.11  编写并验证你自己的reset函数，使其作用于引用类型的参数。注：reset即置0。

#include<iostream>
using std::cout;
using std::endl;

void reset(int &i)
{
    i = 0;
}

int main()
{
    int i = 1;
    cout << "i = " << i << endl;
    reset(i);
    cout << "i = " << i << endl;
    return 0;
}