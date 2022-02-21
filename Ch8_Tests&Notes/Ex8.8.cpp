//Ex8.8   修改上一题的程序，将结果追加到给定的文件末尾。对同一个输出文件，运行程序至少两次，检验数据是否得以保留。

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;

// Sales_data copy from P229
int main(int argc, char **argv)
{
    ifstream ifs(argv[1]);//read in
    ofstream ofs(argv[2], ofstream::app);//save output
    //ofstream::app 指定app模式防止数据丢失

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