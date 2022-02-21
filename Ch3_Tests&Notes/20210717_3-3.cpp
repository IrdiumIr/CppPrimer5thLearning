//3.17   从cin读入一组词并把它们存入一个vector对象，然后设法把所有词都改为大写形式。输出改变后的结果，每个词占一行。
//解：
// #include <iostream>
// #include <string>
// #include <cctype>
// #include <vector>
// using std::string;
// using std::cin;
// using std::cout;
// using std::endl;
// using std::vector;

// int main()
// {
//     vector<string> vec;
//     string str;
//     while (cin >> str)
//     {
//         vec.push_back(str);
//     }
//     for (auto &s : vec)
// 	{
// 		for (auto &c : s)
// 		{
// 			c = toupper(c);
// 		}
// 	}
//     for (auto &i : vec)
//     {
//         cout << i << endl;
//     }
//     return 0;
// }

//3.18   下面的程序合法吗？如果不合法，你准备如何修改？
//      vector<int> ivec;
//      ivec[0] = 42;
//解：不合法。定义时未初始化的空vector容器不能直接使用下标进行访问。
//    应该使用ivec.pushback(42)；

//3.19   如果想定义一个含有10个元素的vector对象，所有元素的值都是42，请例举三种不同的实现方法，哪种方式更好呢？
//解：  vector<int> ivec1(10, 42);
//      vector<int> ivec2{ 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
//      vector<int> ivec3;
//      for (int i = 0; i < 10; ++i)
// 	    ivec3.push_back(42);
//      第一种最好。

//3.20   读入一组整数并把他们存入一个vector对象，将每对相邻整数的和输出出来。
//       改写你的程序，这次要求先输出第一个和最后一个元素的和，接着输出第二个和倒数第二个元素的和，以此类推。
//解：
// #include <iostream>
// #include <string>
// #include <cctype>
// #include <vector>
// using std::cin;
// using std::cout;
// using std::endl;
// using std::string;
// using std::vector;

// int main()
// {
// 	vector<int> ivec;
// 	int i;
// 	while (cin >> i)
// 	{
// 		ivec.push_back(i);
// 	}
// 	for (string::size_type i = 0; i < ivec.size() - 1; ++i)
// 	{
// 		cout << ivec[i] + ivec[i + 1] << endl;
// 	}

// 	cout << "---------------------------------" << endl;

// 	int m = 0;
// 	int n = ivec.size() - 1;
// 	while (m < n)
// 	{
// 		cout << ivec[m] + ivec[n] << endl;
// 		++m;
// 		--n;
// 	}
// 	return 0;
// }

//3.21   请使用迭代器重做3.3.3节的第一个练习。
//解：
// #include <iostream>
// #include <string>
// #include <vector>
// #include <iterator>

// using std::vector;
// using std::string;
// using std::cin;
// using std::cout;
// using std::endl;

// void check_and_print(const vector<int>& vec)
// {
// 	cout << "size: " << vec.size() << "  content: [";
// 	for (auto it = vec.begin(); it != vec.end(); ++it)
// 		cout << *it << (it != vec.end() - 1 ? "," : "");
// 	cout << "]\n" << endl;
// }

// void check_and_print(const vector<string>& vec)
// {

// 	cout << "size: " << vec.size() << "  content: [";
// 	for (auto it = vec.begin(); it != vec.end(); ++it)
// 		cout << *it << (it != vec.end() - 1 ? "," : "");
// 	cout << "]\n" << endl;
// }

// int main()
// {
//     vector<int> v1;         // size:0,  no values.
//     vector<int> v2(10);     // size:10, value:0
//     vector<int> v3(10, 42); // size:10, value:42
//     vector<int> v4{ 10 };     // size:1,  value:10
//     vector<int> v5{ 10, 42 }; // size:2,  value:10, 42
//     vector<string> v6{ 10 };  // size:10, value:""
//     vector<string> v7{ 10, "hi" };  // size:10, value:"hi"      //from 3.16

// 	check_and_print(v1);
// 	check_and_print(v2);
// 	check_and_print(v3);
// 	check_and_print(v4);
// 	check_and_print(v5);
// 	check_and_print(v6);
// 	check_and_print(v7);

// 	return 0;
// }

//3.22   修改之前那个输出text第一段的程序，首先把text的第一段全部改成大写形式，然后输出它。
//解：
// #include <iostream>
// #include <vector>
// #include <string>
// #include <cctype>

// using std::vector;
// using std::string;
// using std::cout;
// using std::cin;
// using std::endl;
// using std::isalpha;

// int main()
// {
//     vector<string> text;
//     for (string line; getline(cin, line); text.push_back(line));
//     for (auto str = text.begin(); str != text.end(); ++str)
//     {
//         // cout << *str;
//         for (auto strout = (*str).begin(); strout != (*str).end(); ++strout)
//         {
//             if (isalpha(*strout))
//             {
//                 *strout = toupper(*strout);
//             }
//             cout << *strout;
//         }
//     }
//         return 0;
// }

//3.23   编写一段程序，创建一个含有10个整数的vector对象，然后使用迭代器将所有元素的值都变成原来的两倍。输出vector对象的内容，检验程序是否正确。
//解：
// #include <iostream>
// #include <vector>
// #include <iterator>

// using std::cin;
// using std::cout;
// using std::endl;
// using std::iterator;
// using std::vector;

// int main()
// {
// 	vector<int> v(10, 1);
//     for (auto it = v.begin(); it != v.end(); it++)
//     {
//         *it *= 2;
//     }
//     for (auto i : v)
//     {
//         cout << i << " ";
//     }
// 	return 0;
// }

//3.24   请使用迭代器重做3.3.3节的最后一个练习。
//解：
// #include <iostream>
// #include <vector>

// using std::cin;
// using std::cout;
// using std::endl;
// using std::vector;

// int main()
// {
//     vector<int> ivec;
//     int i;
//     while (cin >> i)
//     {
//         ivec.push_back(i);
//     }

//     for (auto it = ivec.cbegin(); it != ivec.cend() - 1; ++it)
//     {
//         cout << *it + *(it + 1) << endl;
//     }

//     cout << "---------------------------------" << endl;

//     auto it1 = ivec.begin();
//     auto it2 = ivec.end() - 1;
//     while (it1 < it2)
//     {
//         cout << *it1 + *it2 << endl;
//         ++it1;
//         --it2;
//     }
//     return 0;
// }

//3.25   3.3.3节划分分数段的程序是使用下标运算符实现的，请利用迭代器改写该程序实现完全相同的功能。
//解：
// #include <iostream>
// #include <vector>

// using std::cout;
// using std::cin;
// using std::endl;
// using std::vector;

// int main()
// {
// 	vector<unsigned> scores(11, 0);
// 	unsigned grade;
// 	while (cin >> grade)
// 	{
// 		if (grade <= 100)
//             ++*(scores.begin() + grade / 10);   //++scores[grade/10];
//     }
// 	for (auto s : scores)
// 		cout << s << " ";
// 	return 0;
// }

//3.26   为什么用的是 mid = beg + (end - beg) / 2, 而非 mid = (beg + end) / 2 ; ?
//解：   迭代器之间无法做减法。P99

//3.27   假设txt_size是一个无参函数，它的返回值是int。请回答下列哪个定义是非法的，为什么？
// unsigned buf_size = 1024;
// (a) int ia[buf_size];
// (b) int ia[4 * 7 - 14];
// (c) int ia[txt_size()];
// (d) char st[11] = "fundamental";
//解：     (a)非法，buf_size不是const；(b)合法，4*7-14是const；(c)非法，txt_size不是const；(d)非法，"fundamental"还有空位

//3.28   列数组中元素的值是什么？
// string sa[10];
// int ia[10];
// int main() {
// 	string sa2[10];
// 	int ia2[10];
// }
//解：  分别为"",0,"",未定义

//3.29   相比于vector 来说，数组有哪些缺点，请列举一些。
//解：   1.无法改变数组大小；2.无法增加对象；3.无法赋值

//3.30   指出下面代码中的索引错误。
//      constexpr size_t array_size = 10;
//      int ia[array_size];
//      for (size_t ix = 1; ix <= array_size; ++ix)
// 	    ia[ix] = ix;
//解：  ix <= 10，当ix = 10时，数组越界。

//3.31   编写一段程序，定义一个含有10个int的数组，令每个元素的值就是其下标值。
//解：
// #include <iostream>

// using std::cin;
// using std::cout;
// using std::endl;

// int main()
// {
//     int arr[10];
//     for (auto i = 0; i != 10; ++i) 
//     {
//         arr[i] = i;
//     }
//     for (auto i : arr)
//         cout << i << " ";
//     cout << endl;
//     return 0;
// }

//3.32   将上一题刚刚创建的数组拷贝给另一数组。利用vector重写程序，实现类似的功能。
//解：
// #include <iostream>
// #include <vector>

// using std::cin;
// using std::cout;
// using std::endl;
// using std::vector;

// int main()
// {
//     int arr1[10];
//     for (auto i = 0; i != 10; ++i) 
//     {
//         arr1[i] = i;
//     }
//     int arr2[10];
//     for (auto i = 0; i != 10; ++i) 
//     {
//         arr2[i] = arr1[i];
//     }
//     //  copy arr1 to arr2,using arr

//     vector<int> v1(10);
//     for (auto i = 0; i != 10; ++i)
//     {
//         v1[i] = arr1[i];
//     }
//     vector<int> v2(v1);
//     for (auto i : v2)
//     {
//         cout << i << " ";
//     }
//     cout << endl;
//     return 0;
//     //  copy v1 to v2,using vector
// }

//3.33   对于104页的程序来说，如果不初始化scores将会发生什么？
//解：  初始值会成为未定义值。

//3.34   假定p1 和 p2 都指向同一个数组中的元素，则下面程序的功能是什么？什么情况下该程序是非法的？
//      p1 += p2 - p1;
//解：  p1 += p2 - p1即为p1 = p1 + p2 - p1，即为p1 = p2。使得p1和p2指向同一个地址，是合法的。

//3.35   编写一段程序，利用指针将数组中的元素置为0。
//解：
// #include <iostream>

// using std::cin;
// using std::cout;
// using std::endl;

// int main()
// {
//     int arr[10];
//     for (int *p = arr; p != arr + 10; ++p)
//     {
//         *p = 0;
//     }
//     for (auto i : arr) 
//         cout << i << " ";
//     cout << endl;
// }

//3.36   编写一段程序，比较两个数组是否相等。再写一段程序，比较两个vector对象是否相等。
//解：
// #include <iostream>
// #include <vector>
// #include <iterator>

// using std::begin;
// using std::cin;
// using std::cout;
// using std::end;
// using std::endl;
// using std::vector;

// int main()
// {
//     int arr1[3] = { 0, 1, 2 };
//     int arr2[3] = { 0, 1, 3 };

//     int *pbeg1 = begin(arr1);
//     int *pend1 = end(arr1);
//     int *pbeg2 = begin(arr2);
//     int *pend2 = end(arr2);

//     if (pend2 - pbeg2 != pend1 - pbeg1)
//     {
//         cout << "Not Equal!" << endl;
//     }
//     //  compare size
//     else
//     {
//         int sign = 1;//    to control output
//         for (int *i = pbeg1, *j = pbeg2; (i != pend1) && (j != pend2); ++i, ++j)
//         {
//             if (*i != *j)
//             {
//                 sign = 0;
//             }
//         }
//         if(sign == 0)
//             cout << "Not Equal!" << endl;
//         else
//             cout << "Equal!" << endl;
//     }
//     //  using arr to compare

//     vector<int> vec1 = { 0, 1, 2 };
//     vector<int> vec2 = { 0, 1, 2 };

//     if (vec1 == vec2)
//         cout << "Equal." << endl;
//     else
//         cout << "Not Equal." << endl;

//     return 0;
// }

//3.37   下面的程序是何含义，程序的输出结果是什么？
//      const char ca[] = { 'h', 'e', 'l', 'l', 'o' };
//      const char *cp = ca;
//      while (*cp) {
//      cout << *cp << endl;
//      ++cp;
//      }
//解：  会把字符数组内的字符依次输出。但是当*cp指针指向后面的空间时，将输出无法预料的结果。

//3.38   在本节中我们提到，将两个指针相加不但是非法的，而且也没有什么意义。请问为什么两个指针相加没有意义？
//解：  指针相减表示两个指针之间的距离，指针 + 整数表示对指针进行移动；但是指针相加没有逻辑上的意义。

//3.39   编写一段程序，比较两个 string 对象。再编写一段程序，比较两个C风格字符串的内容。
//解：
// #include <iostream>
// #include <string>
// #include <cstring>

// using std::cin;
// using std::cout;
// using std::endl;
// using std::string;

// int main()
// {
//     string s1("Hust"), s2("Wnlo");
//     if (s1 == s2)
//         cout << "They are the same." << endl;
//     else if (s1 > s2)
//         cout << "Hust > Wnlo" << endl;
//     else
//         cout << "Hust < Wnlo" << endl;

//     cout << "------------" << endl;

//     const char *cs1 = "Hust";
//     const char *cs2 = "Wnlo";
//     if (strcmp(cs1, cs2) == 0)
//         cout << "They are the same." << endl;
//     else if (strcmp(cs1, cs2) > 0)
//         cout << "Hust > Wnlo" << endl;
//     else
//         cout << "Hust < Wnlo" << endl;
//     return 0;
// }

//3.40   编写一段程序，定义两个字符数组并用字符串字面值初始化它们；接着再定义一个字符数组存放前面两个数组连接后的结果。
//       使用strcpy和strcat把前两个数组的内容拷贝到第三个数组当中。
//解：
// #include <iostream>
// #include <cstring>

// using std::cout;
// using std::endl;

// int main()
// {
//     char cstr1[] = "Hust";
//     char cstr2[] = "Wnlo";
//     // const auto len1 = strlen(cstr1);
//     // const auto len2 = strlen(cstr2);
    
//     /* error:无法调用非 constexpr 函数 "strlen" */

//     constexpr auto size3 = sizeof(cstr1) + sizeof(cstr2) + 2;
//     // sizeof(cstr1)
//     // constexpr auto size3 = len1 + len2 + 2;
//     char cstr3[size3];
    
//     strcpy(cstr3, cstr1);
//     strcat(cstr3, " ");
//     strcat(cstr3, cstr2);

//     cout << cstr3 << endl;
// }

//3.41   编写一段程序，用整型数组初始化一个vector对象。
//解：
// #include <iostream>
// #include <vector>

// using std::cout;
// using std::endl;
// using std::vector;
// using std::begin;
// using std::end;

// int main()
// {
//     int arr[] = { 0, 1, 2, 3, 4 };
//     vector<int> v(begin(arr), end(arr));
//     for (auto i : v)
//         cout << i << " ";
//     cout << endl;
//     return 0;
// }

//3.42   编写一段程序，将含有整数元素的 vector 对象拷贝给一个整型数组。
//解：
// #include <iostream>
// #include <vector>

// using std::cout;
// using std::endl;
// using std::vector;
// using std::begin;
// using std::end;

// int main()
// {
//     vector<int> v{ 0, 1, 2, 3, 4, 5 };
//     int arr[10];
//     for (vector<int>::size_type i = 0; i != v.size(); ++i)
//         arr[i] = v[i];
//     for (auto i : arr)
//         cout << i << " ";
//     cout << endl;
//     return 0;
// }

//3.43   编写 3 个不同版本的程序，令其均能输出 ia 的元素。
//      版本 1 使用范围 for 语句管理迭代过程；版本 2 和版本 3 都使用普通 for 语句，其中版本 2 要求使用下标运算符，版本 3 要求使用指针。
//      此外，在所有 3 个版本的程序中都要直接写出数据类型，而不能使用类型别名、auto 关键字和 decltype 关键字。
//解：
// #include <iostream>

// using std::cout; 
// using std::endl;

// int main()
// {
//     int ia[3][4] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

//     // for
//     for (int (&row) [4] : ia)
//         for (int col : row)
//             cout << col << " ";
//     cout << endl;
//     // row是对含有4个int的数组的引用，在ia中进行遍历，共3次；col是在每个row中进行遍历，共4次（4个int）

//     // for [i][j]
//     for (int i = 0; i != 3; ++i)
//         for (int j = 0; j != 4; ++j)
//             cout << ia[i][j] << " ";
//     cout << endl;

//     // for pointer
//     for (int (*row) [4] = ia; row != ia + 3; ++row)
//         for (int *col = *row; col != *row + 4; ++col)
//             cout << *col << " ";
//     cout << endl;
//     // row是指向ia的第一行（4个int的数组）的指针；ia数组名转换为指向ia第一行的指针，ia+3为ia第 4 行
//     // col是一个指向row第一个元素的指针（*row解引用后为含有4个int的数组），*row+4转换为指向row第5个位置的指针
//     // 此处解引用了 2 次

//     return 0;
// }

//3.44   改写上一个练习中的程序，使用 类型别名 来代替循环控制变量的类型。
//解：
// #include <iostream>

// using std::cout; 
// using std::endl;

// int main()
// {
//     int ia[3][4] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    
//     using int_array = int[4];// int_array为别名
    
//     for (int_array &p : ia)
//         for (int q : p)
//             cout << q << " ";
//     cout << endl;
    
//     // for [i][j],无别名
//     for (int i = 0; i != 3; ++i)
//         for (int j = 0; j != 4; ++j)
//             cout << ia[i][j] << " ";
//     cout << endl;

//     // for pointer,int_array别名
//     for (int_array *p = ia; p != ia + 3; ++p)
//         for (int *q = *p; q != *p + 4; ++q)
//             cout << *q << " ";
//     cout << endl;

//     return 0;
// }

//3.45   再一次改写程序，这次使用 auto 关键字。
//解：
#include <iostream>

using std::cout; 
using std::endl;

int main()
{
    int ia[3][4] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    
    // auto for
    for (auto &p : ia)
        for (auto q : p)
            cout << q << " ";
    cout << endl;
    
    // for [i][j]
    for (auto i = 0; i != 3; ++i)
        for (auto j = 0; j != 4; ++j)
            cout << ia[i][j] << " ";
    cout << endl;

    // for pointer
    for (auto p = ia; p != ia + 3; ++p)
        for (auto q = *p; q != *p + 4; ++q)
            cout << *q << " ";
    cout << endl;

    return 0;
}