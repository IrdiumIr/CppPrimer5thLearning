//Ex8.7   修改上一节的书店程序，将结果保存到一个文件中。将输出文件名作为第二个参数传递给main函数。

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
    ofstream ofs(argv[2]);//save output

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
                print(ofs, total) << endl;
                total = trans;
            }
        }
        print(ofs, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }
    
    return 0;
}