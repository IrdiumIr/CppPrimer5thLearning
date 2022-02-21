//Ex5.14  编写一段程序，从标准输入中读取若干string对象并查找连续重复出现的单词，所谓连续重复出现的意思是：一个单词后面紧跟着这个单词本身。要求记录连续重复出现的最大次数以及对应的单词。
//        如果这样的单词存在，输出重复出现的最大次数；如果不存在，输出一条信息说明任何单词都没有连续出现过。 例如：如果输入是： how now now now brown cow cow
//        那么输出应该表明单词now连续出现了3次。

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string str;
    vector<string> strVec;
    string maxStr, tmpStr;      //出现最多的字符串和当前字符串
    int maxCnt = 1, tmpCnt = 1;      //出现最多次数和当前计数
    
    while (cin >> str) { strVec.push_back(str); }
    auto moveStr = strVec.begin();      //逐位比较      //重要：应在pushback后定义moveStr。[此处出错30min+]
    
    while (moveStr != strVec.end())
    {
        tmpStr = *moveStr;
        ++moveStr;

        while (moveStr != strVec.end() && *moveStr == tmpStr)
        {
            ++tmpCnt;
            ++moveStr;
        }
        if (maxCnt <= tmpCnt)
        {
            maxCnt = tmpCnt;
            maxStr = tmpStr;
        }
        tmpCnt = 1;     //置0
    }
    
    if(maxCnt == 1)  
		cout << "No repeated words." << endl;
	else
	{
		cout << "MaxNum of repetition is: " << maxCnt << endl; 
        cout << "Repetition words is: " << maxStr << endl;
    }
    return 0;
}
