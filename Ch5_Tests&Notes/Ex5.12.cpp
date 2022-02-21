//Ex5.12  修改统计元音字母的程序，使其能统计含以下两个字符的字符序列的数量：ff、fl和fi。

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int ffCnt = 0, flCnt = 0, fiCnt = 0; //ff,fl,fi
    char ch1, ch2;
    
    while (cin >> ch1 >> ch2)
    {
        if (ch1 == 'f')
        {
            switch (ch2)
            {   
                case 'f':
                    ++ffCnt;
                    break;
                case 'l':
                    ++flCnt;
                    break;
                case 'i':
                    ++fiCnt;
                    break;
                default:
                    break;
            }
        }
    }
    cout << "Num of ff: " << ffCnt << endl
         << "Num of fl: " << flCnt << endl
         << "Num of fi: " << fiCnt << endl;
}
