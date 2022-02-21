//Ex5.11  修改统计元音字母的程序，使其也能统计空格、制表符、和换行符的数量。

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spCnt = 0, tabCnt = 0, newlCnt = 0; //a,e,i,o,u
    char ch;
    
    while (cin >> ch)
    {
        switch (ch)
        {
            case 'A': case 'a':
                ++aCnt;
                break;
            case 'E': case 'e':
                ++eCnt;
                break;
            case 'I': case 'i':
                ++iCnt;
                break;
            case 'O': case 'o':
                ++oCnt;
                break;
            case 'U': case 'u':
                ++uCnt;
                break;
            case ' ':
                ++spCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case '\n':
                ++newlCnt;
                break;
            default:
                break;
        }
    }
    cout << "Num of A/a: " << aCnt << endl
         << "Num of E/e: " << eCnt << endl
         << "Num of I/i: " << iCnt << endl
         << "Num of O/o: " << oCnt << endl
         << "Num of U/u: " << uCnt << endl
         << "Num of Space: " << spCnt << endl
         << "Num of Tab: " << tabCnt << endl
         << "Num of NewLine: " << newlCnt << endl;
}