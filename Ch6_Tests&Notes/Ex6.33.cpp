//Ex6.33  编写一个递归函数，输出vector对象的内容。

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


static size_t i = 0;

void print(vector<int> vec)
{
    // size_t i = 0;
    if (i != vec.size())
    {
        cout << vec[i++] << " ";
        print(vec);
    }
}

int main()
{
    vector<int> vec{ 1, 2, 3, 4, 5 };
    print(vec);
    return 0;
}
