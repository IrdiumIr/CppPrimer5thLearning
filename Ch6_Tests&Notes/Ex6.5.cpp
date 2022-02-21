//Ex6.5  编写一个函数输出其实参的绝对值。

#include <iostream>

int abs(int i)
{
    return (i > 0) ? i : -i;
}

int main()
{
    std::cout << abs(-1) << std::endl;
    return 0;
}
