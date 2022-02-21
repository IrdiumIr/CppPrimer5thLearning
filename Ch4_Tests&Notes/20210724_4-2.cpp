//4.25  如果一台机器上int占32位、char占8位，用的是Latin-1字符集，其中字符'q' 的二进制形式是01110001。
//      那么表达式~'q' << 6的值是什么？
//解：
//      首先将char类型提升为int类型，在高位补24个0，然后取反后左移6位，结果是
//      1111 1111 1111 1111 1110 0011 1000 0000
//      ans: -7296(补码)

//4.26  在本节关于测验成绩的例子中，如果使用unsigned int 作为quiz1 的类型会发生什么情况？
//解：
//      unsigned int类型的大小和int未必相同，因此可能出现未定义结果。

//4.27  下列表达式的结果是什么？
//      unsigned long ul1 = 3, ul2 = 7;
//      (a) ul1 & ul2
//      (b) ul1 | ul2
//      (c) ul1 && ul2
//      (d) ul1 || ul2
//解：
//      (a) 3; (b) 7; (c) true; (d) true

//4.28  编写一段程序，输出每一种内置类型所占空间的大小。
//解：
// #include <iostream>

// using std::cout;
// using std::endl;

// int main()
// {
// 	cout << "bool:\t\t" << sizeof(bool) << " bytes" << endl << endl;

// 	cout << "char:\t\t" << sizeof(char) << " bytes" << endl;
// 	cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes" << endl;

// 	cout << "short:\t\t" << sizeof(short) << " bytes" << endl;
// 	cout << "int:\t\t" << sizeof(int) << " bytes" << endl;
// 	cout << "long:\t\t" << sizeof(long) << " bytes" << endl;
// 	cout << "unsigned:\t" << sizeof(unsigned) << " bytes" << endl;
//     cout << "long long:\t" << sizeof(long long) << " bytes" << endl << endl;
    
// 	cout << "float:\t\t" << sizeof(float) << " bytes" << endl;
// 	cout << "double:\t\t" << sizeof(double) << " bytes" << endl;
// 	cout << "long double:\t" << sizeof(long double) << " bytes" << endl << endl;

// 	return 0;
// }

//4.29  推断下面代码的输出结果并说明理由。实际运行这段程序，结果和你想象的一样吗？如不一样，为什么？
//      int x[10];   int *p = x;
//      cout << sizeof(x)/sizeof(*x) << endl;
//      cout << sizeof(p)/sizeof(*p) << endl;
//解：
//      第一个输出结果为 10。返回了数组x[10]中元素的个数
//      第二个输出结果为 2。但是实际上未定义，用的是指针所占空间大小去除数组所占空间大小。

//4.30  根据4.12节中的表，在下述表达式的适当位置加上括号，使得加上括号之后的表达式的含义与原来的含义相同。
//      (a) sizeof x + y
//      (b) sizeof p->mem[i]
//      (c) sizeof a < b
//      (d) sizeof f()
//解：
//      (a) (sizeof x) + y; (b) sizeof(p->mem[i]);
//      (c) sizeof (a) < b; (d) sizeof (f())

//4.31  本节的程序使用了前置版本的递增运算符和递减运算符，解释为什么要用前置版本而不用后置版本。
//      要想使用后置版本的递增递减运算符需要做哪些改动？使用后置版本重写本节的程序。
//解：
//      前置版本在4.5节已经阐述过相比后置版本，减少了存储原始值的操作，提高了效率。

//4.32  解释下面这个循环的含义。
//      constexpr int size = 5;
//      int ia[size] = { 1, 2, 3, 4, 5 };
//      for (int *ptr = ia, ix = 0;
//          ix != size && ptr != ia+size;
//          ++ix, ++ptr) { /* ... */ }
//解：
//      首先定义了一个大小为5的数组。进入循环后，对于数组ia遍历，指针ptr和整型ix都是起到一个循环计数的功能。
//      指针ptr从数组ia开头位置，ix从数组大小开始分别计数。

//4.33  根据4.12节中的表说明下面这条表达式的含义。
//      someValue ? ++x, ++y : --x, --y
//解：
//      由于逗号运算符优先级最低，表达式等价于 (someValue ? ++x, ++y : --x), --y
//      左侧是一个?:运算符，若 someValue为真，则执行++x, ++y后，丢弃++x，++y和--y使用逗号运算符。
//      因此最后得到的值还是y。若 someValue为假，则得到--x，并于--y做逗号运算，得到的值为--y。

//4.34  根据本节给出的变量定义，说明在下面的表达式中将发生什么样的类型转换：
//      (a) if (fval)
//      (b) dval = fval + ival;
//      (c) dval + ival * cval;
//解：
//      (a) fval是float，转换为条件内的bool类型；
//      (b) ival是int，转换为float，相加的结果赋值给dval，转换为double；
//      (c) cval是char，在* 运算符两侧，转换为int，相乘的结果转换为double

//4.35  假设有如下的定义：
//      char cval;  int ival;  unsigned int ui;  float fval;  double dval;
//      请回答在下面的表达式中发生了隐式类型转换吗？如果有，指出来。
//      (a) cval = 'a' + 3;
//      (b) fval = ui - ival * 1.0;
//      (c) dval = ui * fval;
//      (d) cval = ival + fval + dval;
//解：
//      (a) 'a'转换为int，相加的和从int转换为char；
//      (b) ival和ui转换为double，结果最后转换为float；
//      (c) ui转换为float，结果转换为double；
//      (d) ival转换为float，与fval相加后转换为double，与dval相加后转换为char

//4.36  假设 i 是int类型，d 是double类型，书写表达式 i*=d 使其执行整数类型的乘法而非浮点类型的乘法。
//解：
//      i *= static_cast<int>(d);

//4.37  练习4.37 用命名的强制类型转换改写下列旧式的转换语句。
//      int i; double d; const string *ps; char *pc; void *pv;
//      (a) pv = (void*)ps;
//      (b) i = int(*pc);
//      (c) pv = &d;
//      (d) pc = (char*)pv;
//解：
//      (a) pv = const_cast<string*>(ps)
//      (b) i = static_cast<int>(*pc)
//      (c) pv = static_cast<void*>(&d)
//      (d) pc = static_cast<char*>(pv)

//4.38  说明下面这条表达式的含义。
//      double slope = static_cast<double>(j/i);
//解：
//      j/i的结果值(int)转换为double，赋值给slope。