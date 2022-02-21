//Ex6.47  改写6.3.2节练习中使用递归输出vector内容的程序，使其有条件地输出与执行过程有关的信息。
//        例如，每次调用时输出vector对象的大小。分别在打开和关闭调试器的情况下编译并执行这个程序。

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


static size_t i = 0;

void print(vector<int> vec)
{
#ifndef NDEBUG
    cout << "vector size: " << vec.size() << endl; 
#endif
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
