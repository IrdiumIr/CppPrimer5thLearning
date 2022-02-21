//Ex5.21  修改5.5.1节练习题的程序，使其找到的重复单词必须以大写字母开头。

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string read, tmp;       //初始化为空字符串，因此可以直接cin输入进行对比
    int sig = 1;

    while (cin >> read)
    {
        if (read == tmp)
        {
            if (!isupper(read[0]))
                continue;
                
            sig = 0;
            cout << "Repetition: " << read << endl;
            break;      //检测到重复则直接break
        }
        tmp = read;
    }
    if (sig)
        cout << "No repetition." << endl;
    return 0;
}
