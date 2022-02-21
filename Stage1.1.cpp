//  更改了readIn和printOut函数，使用了const string &

//  对于string_view和string const&，本程序并未使用到对单个string进行操作的内容，在输出时只是对vector本身操作。
//  在了解string_view后，了解到其是一种类似const &的传递只读数据的方式。
//  但是const &存在的问题是：字符串字面值、字符数组、字符串指针的传递不能像string一样直接操作，需要进行转换。
//  所以这个时候还是需要进行copy，降低了性能。这种时候使用string_view的话，可以避免string &的这些问题。
//  在本练习中，所有输入的内容都是string类型，没有字面值、数组和指针，因此使用两者应该都没有问题。
//  
#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<string> readIn2();     // readIn函数声明
void printOut2(const vector<string> &text, size_t linenumber);    // printOut函数声明

int main()
{
    vector<string> text;
    text = readIn2();

    cout << "Total lines are: " << text.size() << endl;    //调用readIn2函数读入vector，并测试是否正确读入
    cout << "Texts have been read." << endl;
    cout << "Enter the line Number: ";

    cin.clear();    //刷新输入流，否则无法进行输入linenumber操作

    size_t linenumber;
    cin >> linenumber;

    printOut2(text, linenumber);

    return 0;
}
//  func1:read in
vector<string> readIn2()
{
    string str;
    vector<string> text;
    while (getline(cin,str))
    {
        text.push_back(str);
    }
    return text;
}

//  func2:print out  
void printOut2(const vector<string> &text, size_t linenumber)
{
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