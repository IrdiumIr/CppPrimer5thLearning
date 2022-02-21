//2.27   下面的哪些初始化是合法的？请说明原因。
//解：      int i = -1, &r = 0;         // 不合法, r 初始化时必须引用一个对象
//          int *const p2 = &i2;        // 合法，常量指针，指向int
//          const int i = -1, &r = 0;   // 合法，r 常量引用初始化时可以使用任意初始值
//          const int *const p3 = &i2;  // 合法，指向常量的常量指针
//          const int *p1 = &i2;        // 合法，指向常量int的指针
//          const int &const r2;        // 不合法, r2 是引用，引用没有顶层 const
//          const int i2 = i, &r = i;   // 合法，常量引用

//2.28   说明下面的这些定义是什么意思，挑出其中不合法的。
//解：      int i, *const cp;       // 不合法, int *const cp 指针必须初始化
//          int *p1, *const p2;     // 不合法, int *const p2 指针必须初始化
//          const int ic, &r = ic;  // 不合法, const int ic 必须初始化
//          const int *const p3;    // 不合法, const int *const p3 指针必须初始化
//          const int *p;           // 合法. 一个指针，指向 const int（指针可不初始化）

//2.29   假设已有上一个练习中定义的那些变量，则下面的哪些语句是合法的？请说明原因。
//解：      i = ic;     // 合法, 常量 ic 赋值给普通变量 i
//          p1 = p3;    // 不合法, p3 是const指针不能赋值给普通指针
//          p1 = &ic;   // 不合法, 普通指针不能指向常量
//          p3 = &ic;   // 不合法, p3 是const指针且指向常量，不能改变
//          p2 = p1;    // 不合法, p2 是常量指针，地址不变
//          ic = *p3;   // 不合法, ic是 const 不能赋值

//2.30   对于下面的这些语句，请说明对象被声明成了顶层const还是底层const？
//       const int v2 = 0; int v1 = v2;
//       int *p1 = &v1, &r1 = v1;
//       const int *p2 = &v2, *const p3 = &i, &r2 = v2;
//解：      v2 顶层；p2 底层；p3 顶层/底层；r2 底层

//2.31   假设已有上一个练习中所做的那些声明，则下面的哪些语句是合法的？
//       请说明顶层const和底层const在每个例子中有何体现。
//解：  r1 = v2; // 合法, v2 顶层const在拷贝时不受影响
//      p1 = p2; // 不合法, p2 是底层const，如果要拷贝必须要求 p1 也是底层const
//      p2 = p1; // 合法, int* 可以转换成const int*
//      p1 = p3; // 不合法, p3 是一个底层const，p1 不是
//      p2 = p3; // 合法, p2 和 p3 都是底层const，拷贝时忽略掉顶层const

//2.32   下面的代码是否合法？如果非法，请设法将其修改正确。
//解：  int null = 0, *p = null;
//      非法。
//      int null = 0;
//      int *p = &null;

//2.33   利用本节定义的变量，判断下列语句的运行结果。
//解：  a=42; // a 是 int
//      b=42; // b 是一个 int,(ci的顶层const在拷贝时被忽略掉了)
//      c=42; // c 也是一个int，cr是ci的别名
//      d=42; // d 是一个 int 指针,所以语句非法，*d=42
//      e=42; // e 是一个 const int *, 所以语句非法 e=&c
//      g=42; // g 是一个 const int 的引用，引用都是底层const，所以不能被赋值

//2.34   基于上一个练习中的变量和语句编写一段程序，输出赋值前后变量的内容，你刚才的推断正确吗？
//解：  
#include <iostream>

int main()
{
    int i = 0, &r = i;
    auto a = r;   // a is an int (r is an alias for i, which has type int)

    const int ci = i, &cr = ci;
    auto b = ci; // b is an int (top-level const in ci is dropped)
    auto c = cr; // c is an int (cr is an alias for ci whose const is top-level)
    auto d = &i; // d is an int* (& ofan int objectis int*)
    auto e = &ci; // e is const int*(& of a const object is low-level const)
    // const auto f = ci; // deduced type of ci is int; f has type const int
    // auto &g = ci; // g is a const int& that is bound to ci
    
    std::cout << a << ' ' << b << ' ' << c << ' ' << *d << ' ' << *e << std::endl;
    
    a = 42; b = 42; c = 42; *d = 42; e = &ci;

    std::cout << a << ' ' << b << ' ' << c << ' ' << *d << ' ' << *e << std::endl;

    return 0;
}