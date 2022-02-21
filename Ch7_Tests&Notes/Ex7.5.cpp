//Ex7.5  在你的Person类中提供一些操作使其能够返回姓名和地址。 这些函数是否应该是const的呢？解释原因。

#include <string>
using std::string;

struct Person
{
    string name;
    string address;

    string getName() const { return name; }
    string getAddress() const { return address; }
};

// 应当是const的。因为在调用常量Person类中的name和address时，只能调用常量成员函数。
// 由于不能使用普通的成员函数来调用常量，因此需要把这些函数设置为const的。