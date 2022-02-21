//Ex7.12  把只接受一个istream作为参数的构造函数移到类的内部。

#include <string>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

struct Sales_data
{
    // 移动构造函数
    Sales_data() = default;
    Sales_data(const string &s) : bookNo(s) { }
    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) { }
    // Sales_data(istream &is);
    Sales_data(istream &is) { read(is, *this); }

    string isbn() const { return bookNo; };
    Sales_data& combine(const Sales_data&);
    
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

// Sales_data::Sales_data(istream &is)
// {
//     read(is, *this);
// }

int main()
{
    Sales_data item1;//struct func1
    print(cout, item1) << endl;
    
    Sales_data item2("ISBN");//struct func2
    print(cout, item2) << endl;
    
    Sales_data item3("ISBN", 2, 19.98);//struct func3
    print(cout, item3) << endl;
    
    Sales_data item4(cin);//struct func4
    print(cout, item4) << endl;
    
    return 0;
}