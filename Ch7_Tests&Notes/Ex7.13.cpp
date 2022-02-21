//Ex7.13  使用istream构造函数重写第229页的程序。

#include <string>
#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

int main()
{
    Sales_data total(cin); //Sales_item total;
    if (cin) // if (cin >> total.bookNo >> total.units_sold >> total.revenue)
    {
        istream &is = cin;
        //Sales_data trans(is);//Sales_item trans
        while (is) 
        {
            Sales_data trans(is);
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(cout, total) << endl;
                //cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
        //cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
    }
    else
    {
        cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
