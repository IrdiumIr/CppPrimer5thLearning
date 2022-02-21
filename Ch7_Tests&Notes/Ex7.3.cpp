//Ex7.3  修改7.1.1节的交易处理程序，令其使用这些成员。

int main()
{
    Sales_data total; //Sales_item total;
    if (cin >> total.bookNo >> total.units_sold >> total.revenue)
    {
        Sales_data trans;//Sales_item trans
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) 
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
