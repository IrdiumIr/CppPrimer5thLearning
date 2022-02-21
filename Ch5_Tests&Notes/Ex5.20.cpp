//Ex5.20  编写一段程序，从标准输入中读取string对象的序列直到连续出现两个相同的单词或者所有的单词都读完为止。
//        使用while循环一次读取一个单词，当一个单词连续出现两次时使用break语句终止循环。
//        输出连续重复出现的单词，或者输出一个消息说明没有任何单词是连续重复出现的。

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
