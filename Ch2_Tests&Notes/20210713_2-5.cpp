//ex2.9-2.10
//2.9   解释下列定义的含义，对于非法的定义，请说明错在何处并将其改正。
//(a)   std::cin >> int input_value;
//(b)   int i = { 3.14 };
//(c)   double salary = wage = 9999.99;
//(d)   int i = 3.14;
//解：
//(a)   int input_value = 0;
//      std::cin >> input_value;    先定义再使用
//(b)   double i = { 3.14 };    列表初始化内置类型，int i会丢失信息，报错
//(c)   double wage;
//      double salary = wage = 9999.99;     wage未定义
//(d)   double i = 3.14;    不报错，但是 i = 3 会丢失信息

//2.10   下列变量的初值分别是什么？
//      std::string global_str;
//      int global_int;
//      int main()
//      {
//          int local_int;
//          std::string local_str;
//      }
//解：
//global_str和global_int在函数体外，初值分别为空字符串和0。
//local_int在函数体内，没有初始化，初值未定义。
//local_str是string类的对象，它的值由类确定。