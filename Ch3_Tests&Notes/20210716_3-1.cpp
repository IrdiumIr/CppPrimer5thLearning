//3.1   使用恰当的using声明重做 1.4.1节和2.6.2节的练习。
//解：
// #include <iostream>;
// using std::cin;
// using std::cout;
// using std::endl;

// int main()
// {
// 	int sum = 0;
// 	for (int val = 1; val <= 10; ++val) sum += val;
// 	cout << "Sum of 1 to 10 inclusive is " << sum << endl;
// 	return 0;
// }

//3.2   编写一段程序从标准输入中一次读入一行，然后修改该程序使其一次读入一个词。
//解：
// #include <iostream>
// #include <string>
// using std::cin;
// using std::cout;
// using std::endl;
// using std::getline;
// using std::string;

// int main()
// {
//     string s;
//     while (getline(cin,s))   //while (cin >> s)
//     {
//         cout << s << endl;
//     }
//     return 0;
// }

//3.3   请说明string类的输入运算符和getline函数分别是如何处理空白字符的。
//解：  类似is >> s的读取：string对象会 ( 忽略 ) 开头的空白并从第一个真正的字符开始，直到遇见下一 ( 空白 ) 为止。
//      类似getline(is, s)的读取：string对象会从输入流中读取字符，直到遇见 ( 换行符 ) 为止。

//3.4   编写一段程序读取两个字符串，比较其是否相等并输出结果。如果不相等，输出比较大的那个字符串。
//      改写上述程序，比较输入的两个字符串是否等长，如果不等长，输出长度较大的那个字符串。
//解：  
// #include <iostream>
// #include <string>
// using std::cin;
// using std::cout;
// using std::endl;
// using std::getline;
// using std::string;

// int main()
// {
//     string s1, s2;
//     while (cin >> s1 >>s2)
//     {
//         if(s1 == s2)
//             cout << "Two strings are equal." << endl;
//         else
//             cout << "Larger one is " << ((s1 > s2) ? s1 : s2);
//     }
//     return 0;
// }
// int main()
// {
//     string s1, s2;
//     while (cin >> s1 >>s2)
//     {
//         if(s1.size() == s2.size())
//             cout << "Two strings are equal long." << endl;
//         else
//             cout << "Longer one is " << ((s1.size() > s2.size()) ? s1 : s2) << endl;
//     }
//     return 0;
// }

//3.5   编写一段程序从标准输入中读入多个字符串并将他们连接起来，输出连接成的大字符串。然后修改上述程序，用空格把输入的多个字符串分割开来。
//解：
// #include <iostream>
// #include <string>
// using std::string;
// using std::cin;
// using std::cout;
// using std::endl;

// int main()
// {
// 	string result, s;
// 	while (cin >> s)
// 	{
// 		result += s;        //result += s + " ";
// 	}
// 	cout << result << endl;
// 	return 0;
// }
