//Ex5.6  改写上一题的程序，使用条件运算符代替if else语句。

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> scores = { "F", "D", "C", "B", "A", "S" };
    int grade;      //成绩数字,int
    string suffix;      //成绩等第后缀,string

    while (cin >> grade)
    {
        suffix = (grade < 60) ? scores[0] : scores[(grade - 50) / 10];
        suffix += (grade == 100 || grade < 60) ? "" : ((grade % 10 > 6) ? "+" : ((grade % 10 < 3) ? "-" : ""));
        cout << suffix << endl;     //grade = 100 & < 60,无后缀；其余参照5.5中处理
    }
    return 0;
}
