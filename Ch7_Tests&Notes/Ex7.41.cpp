//Ex7.41  使用委托构造函数重新编写你的Sales_data类，给每个构造函数体添加一条语句，令其一旦执行就打印一条信息。
//        用各种可能的方式分别创建Sales_data对象，认真研究每次输出的信息直到你确实理解了委托构造函数的执行顺序。

#include <string>
#include <iostream>
using std::cin; using std::cout; using std::endl; 
using std::istream; using std::ostream; using std::string;

struct Sales_data
{
    friend istream &read(istream &is, Sales_data &item);
    friend ostream &print(ostream &os, const Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

public:
    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n)
    {
        cout << "Sales_data(const string&, unsigned, double)" << endl;
    }
    Sales_data() : Sales_data(" ", 0, 0.0)
    {
        cout << "Sales_data()" << endl;
    }
    Sales_data(const string &s) : Sales_data(s, 0, 0.0)
    {
        cout << "Sales_data(const string&)" << endl;
    }
    Sales_data(istream &is);//已声明，下定义

    string isbn() const { return bookNo; };
    Sales_data& combine(const Sales_data&);

private:
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

Sales_data::Sales_data(istream &is)
{
    cout << "Sales_data(istream &is)" << endl;
    read(is, *this);
}

int main()
{
    cout << "默认构造函数: " << endl;
    Sales_data s1;   
    
    cout << "string参数: " << endl;
    Sales_data s2("Primer5th");
    
    cout << "三参数: " << endl;
    Sales_data s3("Primer5th", 1, 99.8);
    
    cout << "输入流: " << endl;
    Sales_data s4(cin);
    
    return 0;
}