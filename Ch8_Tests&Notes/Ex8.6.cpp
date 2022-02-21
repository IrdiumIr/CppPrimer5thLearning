//Ex8.6   重写7.1.1节的书店程序，从一个文件中读取交易记录。将文件名作为一个参数传递给main。

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using std::ifstream;
using std::string;
using std::vector;

// Sales_data copy from P229
int main(int argc, char **argv)
{
    ifstream ifs(argv[1]);//read in
    
    Sales_data total;
    if (read(ifs, total))
    {
        Sales_data trans;
        while (read(ifs, trans))
        {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }
    
    return 0;
}