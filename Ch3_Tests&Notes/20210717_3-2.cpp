//3.6   编写一段程序，使用范围for语句将字符串内所有字符用X代替。
//解：
// #include <iostream>
// #include <string>
// #include <cctype>
// using std::string;
// using std::cin;
// using std::cout;
// using std::endl;

// int main()
// {
//     string s = "this is a string";
// 	for (auto &c : s)
// 	{
// 		c = 'X';
// 	}
// 	cout << s << endl;
// 	return 0;
// }

//3.7   就上一题完成的程序而言，如果将循环控制的变量设置为char将发生什么？
//解：  不变。

//3.8   分别用while循环和传统for循环重写第一题的程序。
//解：
// #include <iostream>
// #include <string>
// #include <cctype>
// using std::string;
// using std::cin;
// using std::cout;
// using std::endl;

// int main()
// {
// 	string s = "this is a string";
// 	decltype(s.size()) i = 0;
// 	while (i < s.size())        //while
// 	{
// 		s[i] = 'X';
// 		++i;
// 	}
// 	cout << s << endl;
// 	for (i = 0; i < s.size(); ++i)      //for
// 	{
// 		s[i] = 'Y';
// 	}
// 	cout << s << endl;
// 	return 0;
// }
//      范围for 更好，无需依次索引。

//3.9   下面的程序有何作用？它合法吗？如果不合法？为什么？
//      string s;
//      cout << s[0] << endl;
//解：  不合法。不能用下标访问未定义的空字符串。

//3.10   编写一段程序，读入一个包含标点符号的字符串，将标点符号去除后输出字符串剩余的部分。
//解：
// #include <iostream>
// #include <string>
// #include <cctype>
// using std::string;
// using std::cin;
// using std::cout;
// using std::endl;

// int main()
// {
// 	string s = "this, is, a! string!!!";
//     string output;
//     for (auto c : s)
//     {
//         if(!ispunct(c))
//         {
//             output += c;
//         }
//     }
//     cout << output << endl;
//     return 0;
// }

// int main()
// {
//     cout << "Enter a string of characters including punctuation." << endl;
//     for (string s; getline(cin, s); cout << endl)
//     {
//         for (auto i : s)
//         {
//             if (!ispunct(i))
//             {
//                 cout << i;
//             }
//         }
//     }
//     return 0;
// }

//3.11   下面的范围for语句合法吗？如果合法，c的类型是什么？
//      const string s = "Keep out!";
//      for(auto &c : s){ /* ... */ }
//解：  for语句合法。(若不修改c的值) c的类型为 const char &。

//3.12   下列vector对象的定义有不正确的吗？如果有，请指出来。对于正确的，描述其执行结果；对于不正确的，说明其错误的原因。
//解：  vector<vector<int>> ivec;         // 在C++11当中合法
//      vector<string> svec = ivec;       // 不合法，类型不一样(string 和 vector<int>)
//      vector<string> svec(10, "null");  // 合法

//3.13   下列的vector对象各包含多少个元素？这些元素的值分别是多少？
//解：  vector<int> v1;         // size:0,  no values.
//      vector<int> v2(10);     // size:10, value:0
//      vector<int> v3(10, 42); // size:10, value:42
//      vector<int> v4{ 10 };     // size:1,  value:10
//      vector<int> v5{ 10, 42 }; // size:2,  value:10, 42
//      vector<string> v6{ 10 };  // size:10, value:""
//      vector<string> v7{ 10, "hi" };  // size:10, value:"hi"

//3.14   编写一段程序，用cin读入一组整数并把它们存入一个vector对象。
//解：
// #include <iostream>
// #include <string>
// #include <cctype>;
// #include <vector>
// using std::cin;
// using std::cout;
// using std::endl;
// using std::string;
// using std::vector;

// int main()
// {
//     vector<int> v;
//     int i;
//     while (cin >> i)
//     {
//         v.push_back(i);
//     }
//     return 0;
// }

//3.15   改写上题程序，不过这次读入的是字符串。
//解：
// int main()
// {
// 	vector<string> v;
// 	string i;
// 	while (cin >> i)
// 	{
// 		v.push_back(i);
// 	}
// 	return 0;
// } 

//3.16   编写一段程序，把练习3.13中vector对象的容量和具体内容输出出来
//解：
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> v1;         // size:0,  no values.
    vector<int> v2(10);     // size:10, value:0
    vector<int> v3(10, 42); // size:10, value:42
    vector<int> v4{ 10 };     // size:1,  value:10
    vector<int> v5{ 10, 42 }; // size:2,  value:10, 42
    vector<string> v6{ 10 };  // size:10, value:""
    vector<string> v7{ 10, "hi" };  // size:10, value:"hi"

    cout << "v1 size :" << v1.size() << endl;
	cout << "v1 content: ";
	for (auto i : v1)
	{
		cout << i << " , ";
	}
	cout << endl;

    cout << "v2 size :" << v2.size() << endl;
	cout << "v2 content: ";
	for (auto i : v2)
	{
		cout << i << "  ";
	}
	cout << endl;

    cout << "v3 size :" << v3.size() << endl;
	cout << "v3 content: ";
	for (auto i : v3)
	{
		cout << i << "  ";
	}
	cout << endl;

    cout << "v4 size :" << v4.size() << endl;
	cout << "v4 content: ";
	for (auto i : v4)
	{
		cout << i << "  ";
	}
	cout << endl;

    cout << "v5 size :" << v5.size() << endl;
	cout << "v5 content: ";
	for (auto i : v5)
	{
		cout << i << "  ";
	}
	cout << endl;

    cout << "v6 size :" << v6.size() << endl;
	cout << "v6 content: ";
	for (auto i : v6)
	{
		cout << i << "  ";
	}
	cout << endl;

    cout << "v7 size :" << v7.size() << endl;
	cout << "v7 content: ";
	for (auto i : v7)
	{
		cout << i << "  ";
	}
	cout << endl;
}