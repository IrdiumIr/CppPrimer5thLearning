//Ex5.17  假设有两个包含整数的vector对象，编写一段程序，检验其中一个vector对象是否是另一个的前缀。
//        为了实现这一目标，对于两个不等长的vector对象，只需挑出长度较短的那个，把它的所有元素和另一个vector对象比较即可。
//        例如，如果两个vector对象的元素分别是0、1、1、2 和 0、1、1、2、3、5、8，则程序的返回结果为真。

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int i1, i2;
    vector<int> vec1, vec2;
    while (cin >> i1) { vec1.push_back(i1); }
    while (cin >> i2) { vec2.push_back(i2); }
    // vector<int> vec1 = { 0, 1, 1, 2 };
    // vector<int> vec2 = { 0, 1, 1, 2, 3, 5, 8 };
    int signal = 1;     //输出标识

    if (vec1.size() < vec2.size())
    {
        for (int i = 0; i != vec1.size(); ++i)
        {
            if (vec1[i] != vec2[i])
            {
                signal = 0;
            }
        }
    }
    else
    {
        for (int i = 0; i != vec2.size(); ++i)
        {
            if (vec2[i] != vec1[i])
            {
                signal = 0;
            }
        }
    }
    if (signal == 1)
    {
        cout << "是前缀" << endl;
    }
    else
        cout << "不是前缀" << endl;
    return 0;
}
