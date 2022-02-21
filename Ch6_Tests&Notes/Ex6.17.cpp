//Ex6.17  编写一个函数，判断string对象中是否含有大写字母。编写另一个函数，把string对象全部改写成小写形式。在这两个函数中你使用的形参类型相同吗？为什么？

#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;

bool hasUpper(const string &s)
{
	for (auto ch : s)
		if (isupper(ch))
			return true;
	return false;
}

void strToLower(string &s)
{
	for (auto &ch : s)
		if (isupper(ch))
			ch = tolower(ch);
}

int main()
{
	string s = "hello WORLD";
    cout << hasUpper(s) << endl;
    
    strToLower(s);
	cout << s << endl;
    
	return 0;
}
//		形参类型不同，前者是常量引用，后者是普通引用