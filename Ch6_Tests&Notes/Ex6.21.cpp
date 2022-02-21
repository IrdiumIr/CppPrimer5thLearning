//Ex6.21  编写一个函数，令其接受两个参数：一个是int型的数，另一个是int指针。函数比较int的值和指针所指的值，返回较大的那个。在该函数中指针的类型应该是什么？

#include <iostream>
using std::cout;

int compareLarger(const int i, const int *p)
{
    return (i > *p) ? i : *p;
}

int main()
{
    int i = 3;
    cout << "Lager one is: " << compareLarger(2, &i);
    return 0;
}
//      指针的类型是const int *类型