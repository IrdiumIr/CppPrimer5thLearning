//Ex7.23  编写你自己的Screen类型。

#include <string>
using std::string;

class Screen {
    //frined暂缺
    //public别名、构造函数和成员函数
    public:
        using pos = string::size_type;

        Screen() = default;//默认构造函数
        Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c) { }
        //重载的get成员函数
        char get() const { return contents[cursor]; }
        char get(pos r, pos c) const { return contents[r * width + c]; }
    //private数据成员
    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        string contents;
};
