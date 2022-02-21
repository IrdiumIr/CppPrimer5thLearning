//Ex6.27  编写一个函数，它的参数是initializer_list类型的对象，函数的功能是计算列表中所有元素的和。

#include <iostream>
#include <initializer_list>

using std::cout;
using std::endl;
using std::initializer_list;

int sum(initializer_list<int> const &il)
{
    int sum = 0;
    for(auto i : il)
        sum += i;
    return sum;
}
int main()
{
    auto i = { 0, 1, 2, 3, 4, 5, 6 };
    cout << sum(i) << endl;
    return 0;
}
