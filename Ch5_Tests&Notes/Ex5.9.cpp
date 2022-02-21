//Ex5.9  编写一段程序，使用一系列if语句统计从cin读入的文本中有多少元音字母。

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;       //a,e,i,o,u
    char ch;
    
    while (cin >> ch)
    {
        if (ch == 'a') {++aCnt;}
        else if (ch == 'e') {++eCnt;}
        else if (ch == 'i') {++iCnt;}
        else if (ch == 'o') {++oCnt;}
        else if (ch == 'u') {++uCnt;}
    }
    cout << "Num of a: " << aCnt << endl
         << "Num of e: " << eCnt << endl
         << "Num of i: " << iCnt << endl
         << "Num of o: " << oCnt << endl
         << "Num of u: " << uCnt << endl;
}