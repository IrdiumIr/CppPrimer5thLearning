#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool str_subrange(const string& str1, const string& str2)
{
	//大小相同：此时用普通的相等性判断结果作为返回值
	if (str1.size() == str2.size())
		return str1 == str2;	//正确：==运算符返回bool值
	//得到较短string对象的大小
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
	//检查两个string 对象的对应字符是否相等，以较短的字符串长度为限
	for (decltype(size) i = 0; i != size; ++i)
		if (str1[i] != str2[i])
			return ;//错误：没有返回值，编译器将报告这一错误
}

int main(int argc, char** argv)
{

	return 0;
}