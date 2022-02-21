/* 练习项目：简易的文本内容定位器
1. 输入若干段由纯ASCII字符构成的文本（即正常阅读的英文文章），输入指定的行号，输出对应行的内容。
2. 充分考虑运用引用、const 等特性，减少不必要的资源浪费
3. 额外学习C++17中的<string_view> ，思考是使用std::string const& 还是std::string_view ，为什么 */

#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<string> text;    //全局text

void readIn();     // readIn函数声明
void printOut();    // printOut函数声明

int main()
{
    readIn();
    cout << "Total lines are: " << text.size() << endl;    //调用readin函数读入vector，并测试是否正确读入
    cout << "Texts have been read." << endl;
    cout << "Enter the line Number: ";

    cin.clear();    //刷新输入流，否则无法进行输入linenumber操作
    printOut();

    return 0;
}
//  func1:read in
void readIn()
{
    string str;
    while (getline(cin,str))
    {
        text.push_back(str);
    }
}
//  func2:print out  
void printOut()
{
    size_t linenumber;
    cin >> linenumber;

    if (linenumber > 0 && linenumber <= text.size())
    {
        cout << "Designated line found: Line " << linenumber << endl;
        cout << text[linenumber - 1] << endl;
    } 
    else
    {
        cout << "Out of range!" << endl;
    }
}