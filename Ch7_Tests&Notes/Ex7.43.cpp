//Ex7.43  假定有一个名为NoDefault的类，它有一个接受int的构造函数，但是没有默认构造函数。
//        定义类C，C有一个 NoDefault类型的成员，定义C的默认构造函数。

#include <string>
#include <iostream>
using std::cin; using std::cout; using std::endl; 
using std::istream; using std::ostream; using std::string;

struct NoDefault
{
    NoDefault(int i) { }
};

class C
{
    public:
        C() : c(0) { }//默认构造函数无传参，但是需要初始化成员c
    private:
        NoDefault c;
};