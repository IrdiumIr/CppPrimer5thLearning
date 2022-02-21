//Ex5.24  修改你的程序，使得当第二个数是0时抛出异常。先不要设定catch子句，运行程序并真的为除数输入0，看看会发生什么？

#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main()
{
    int i, j;
    cin >> i >> j;
    if (j == 0)
    {
        throw runtime_error("Divisor can't be 0.");
    }
    cout << (i / j) << endl;
    return 0;
}
