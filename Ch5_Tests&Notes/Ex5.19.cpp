//Ex5.19  编写一段程序，使用do while循环重复地执行下述任务： 首先提示用户输入两个string对象，然后挑出较短的那个并输出它。

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str1, str2;
    string sig;
    do {
        cout << "Input two strings: ";
        cin >> str1 >> str2;
        cout << (str1 <= str2 ? str1 : str2) 
             << " is smaller." << endl << endl
             << "If continue, enter y or n: ";
        cin >> sig;
    } while (sig == "y");
    return 0;
}
