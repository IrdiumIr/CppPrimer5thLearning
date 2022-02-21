//Ex6.3  编写你自己的fact函数，上机检查是否正确。注：阶乘。

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

int main()
{
    // int n;
    // std::cin >> n;
    // std::cout << fact(n);    //test n
    return 0;
}
