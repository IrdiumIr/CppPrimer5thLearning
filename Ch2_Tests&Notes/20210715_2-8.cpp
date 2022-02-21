//2.35   判断下列定义推断出的类型是什么，然后编写程序进行验证。
//      const int i = 42;
//      auto j = i; const auto &k = i; auto *p = &i; 
//      const auto j2 = i, &k2 = i;
//解：  j 是 int，k 是 const int的引用；
//      p 是const int *，j2 是const int，k2 是 const int 的引用。

#include <iostream>
#include <typeinfo>

int main()
{
    const int i = 42;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;
    // print i means int, and PKi means pointer to const int.
    std::cout   << "j is "      << typeid(j).name()
                << "\nk is "    << typeid(k).name()
                << "\np is "    << typeid(p).name()
                << "\nj2 is "   << typeid(j2).name()
                << "\nk2 is "   << typeid(k2).name()
                << std::endl;

    return 0;
}

//2.36   关于下面的代码，请指出每一个变量的类型以及程序结束时它们各自的值。
//      int a = 3, b = 4;
//      decltype(a) c = a;
//      decltype((b)) d = a;
//      ++c;
//      ++d;
//解：  c 是 int，值为 4。d 是 int &类型，绑定到 a，a 的值为 4。

//2.37   赋值是会产生引用的一类典型表达式，引用的类型就是左值的类型。
//      也就是说，如果 i 是 int，则表达式 i=x 的类型是 int&。
//      根据这一特点，请指出下面的代码中每一个变量的类型和值。
//      int a = 3, b = 4;
//      decltype(a) c = a;
//      decltype(a = b) d = a;
//解：  c 是 int 类型，值为 3。d 是 int& 类型，绑定到 a。

//2.38   说明由decltype 指定类型和由auto指定类型有何区别。
//       请举一个例子，decltype指定的类型与auto指定的类型一样；
//       再举一个例子，decltype指定的类型与auto指定的类型不一样。
//解：  decltype 处理顶层const和引用的方式与 auto不同，decltype会将顶层const和引用保留起来。
//      int i = 0, &r = i;
//相同
// auto a = i;
// decltype(i) b = i;
//
// //不同 d 是一个 int&，因为r的类型是int &
// auto c = r;
// decltype(r) d = r;
