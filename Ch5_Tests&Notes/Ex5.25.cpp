//Ex5.25  修改上一题的程序，使用try语句块去捕获异常。catch子句应该为用户输出一条提示信息，询问其是否输入新数并重新执行try语句块的内容。

#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main()
{
    for (int i, j; cout << "Input 2 numbers: ", cin >> i >> j;)
    {
        try
        {
            if (j == 0)
            {
                throw runtime_error("Divisor can't be 0.");
            }
            cout << (i / j) << endl;
        }
        catch (runtime_error err)
        {
            cout << err.what() << endl << "Input again? (y/n)" << endl;
            char sig;
            cin >> sig;
            if (sig == 'n')
                break;      //跳出外侧for循环
        }
    }
    return 0;
}
