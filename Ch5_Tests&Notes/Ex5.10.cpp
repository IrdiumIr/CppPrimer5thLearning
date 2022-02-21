//Ex5.10  我们之前实现的统计元音字母的程序存在一个问题：如果元音字母以大写形式出现，不会被统计在内。
//        编写一段程序，既统计元音字母的小写形式，也统计元音字母的大写形式，也就是说，新程序遇到'a'和'A'都应该递增aCnt的值，以此类推。

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
            default:
                break;
        }
    }
    cout << "Num of A/a: " << aCnt << endl
         << "Num of E/e: " << eCnt << endl
         << "Num of I/i: " << iCnt << endl
         << "Num of O/o: " << oCnt << endl
         << "Num of U/u: " << uCnt << endl;
}