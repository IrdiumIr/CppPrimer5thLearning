//Ex5.5  写一段自己的程序，使用if else语句实现把数字转换为字母成绩的要求。

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
        if (grade < 60)
        {
            suffix = scores[0];     //"F"
        }
        else
        {
            suffix = scores[(grade - 50) / 10];
            if (grade != 100)
                suffix += (grade % 10 > 6) ? "+" : ((grade % 10 < 3) ? "-" : ""); //7,8,9 "+";0,1,2 "-"
        }
        cout << suffix << endl;
    }
    return 0;
}
