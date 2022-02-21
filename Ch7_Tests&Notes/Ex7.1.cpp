//Ex7.1  使用2.6.1节定义的Sales_data类为1.6节的交易处理程序编写一个新版本。

#include<iostream>
#include<string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

// 2.6.1定义的Sales_data类
struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sales_data total; //Sales_item total;
    if (cin >> total.bookNo >> total.units_sold >> total.revenue)
    {
        Sales_data trans;//Sales_item trans
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) 
        {
            if (total.bookNo == trans.bookNo)
            {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }
            else
            {
                cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
                total = trans;
            }
        }
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
    }
    else
    {
        cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}