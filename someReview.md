>### someReviews & NOT understood
>* Cpp Primer5th
***
## 22.02.22 
### Ch1
* 1.多文件编译
* 2.CMake等使用
* 3.#ifndef,#define,#endif
### Ch2
* 1.转义字符序列记忆
* 2.指针和constexpr
* 3.typedef char *pstring   ......P61
* 4.C++11 decltype(*p) 得到int&
* 5.左值右值？

## 22.02.23-26
### Ch3
* 1.数组的指针和引用
* 2.指针指向数组元素，也可对指针使用下标运算
* 3.const和constexpr
* 4.多维数组的指针
### Ch4
* 1.递增递减前/后置(改变后/前的值) *iter++
* 2.运算符得到左值右值
* 3.异或(1个1为1)
* 4.sizeof(类成员)可使用域运算，且*p可无效
### Ch5
* 1.throw/try语句
* 2.异常、异常库
### Ch6
* 1.分离式编译
* 2.函数传参时顶层const的忽略问题
* 3.传参尽量定义为const &，保证传参通用性
* 4.main传参
* 5.返回数组指针的不同写法
* 6.局部变量更改不会影响默认实参
* 7.constexpr并非一定返回constexpr，只是字面值
* 8.函数作为形参，通过函数指针的形式(定义和函数指针都行)
* 9.assert预处理宏等

## 22.02.28
### Ch7
* 1.this常量指针 f() const：const成员函数(this指向常量的指针)
* 2.非成员(接口)声明定义均在外部
* 3.return *this
* 4.io流只能用&，无法copy
* 5.public/private  class/struct
* 6.friend('多'加一条类内声明)
* 7.const成员函数可以改变mutable成员
* 8.类内初始化用=和{}
* 9.const成员函数返回*this不能调用普通成员函数
* 10.友元不能传递
* 11.友元声明和作用域
* 12.类型名统一在类开始定义
* 13.参数和成员不要重名，也不要隐藏外部的::
* 14.委托构造函数(利用某个构造函数初始化)
* 15.P262不理解
* 16.单实参构造函数可转化为类类型
* 17.static类外无需，且应在外部初始化
* 18.不完全类型