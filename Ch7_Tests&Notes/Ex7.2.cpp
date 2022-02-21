//Ex7.2  曾在2.6.2节的练习中编写了一个Sales_data类，请向这个类添加combine函数和isbn成员。

#include <string>
using std::string;

struct Sales_data
{
    // add combbine() and isbn()
    string isbn() const { return bookNo; };
    Sales_data& combine(const Sales_data&);
    
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
