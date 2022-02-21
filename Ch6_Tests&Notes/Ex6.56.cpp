//Ex6.56  调用上述vector对象中的每个元素并输出结果。

#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

int add(int a, int b) { return (a + b); }
int subs(int a, int b) { return (a - b); }
int mult(int a, int b) { return (a * b); }
int divi(int a, int b) { return ((b != 0) ? (a / b) : 0); }

int main()
{
    vector<int (*)(int a, int b)> vec;

    vec.push_back(add);
    vec.push_back(subs); 
    vec.push_back(mult);
    vec.push_back(divi);
    
    for (auto f : vec)
    {
        cout << f(1, 2) << endl;
    }
    return 0;
}
