//Ex7.7  使用这些新函数重写7.1.2节练习中的程序。

int main()
{
    Sales_data total; //Sales_item total;
    if (read(cin, total)) // if (cin >> total.bookNo >> total.units_sold >> total.revenue)
    {
        Sales_data trans;//Sales_item trans
        while (read(cin, trans)) 
        {
            // if (total.bookNo == trans.bookNo)
            // {
            //     total.units_sold += trans.units_sold;
            //     total.revenue += trans.revenue;
            // }
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
