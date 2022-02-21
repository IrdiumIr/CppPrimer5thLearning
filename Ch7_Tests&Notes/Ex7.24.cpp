//Ex7.24  给你的Screen类添加三个构造函数：
//        一个默认构造函数；另一个构造函数接受宽和高的值，然后将contents初始化成给定数量的空白；
//        第三个构造函数接受宽和高的值以及一个字符，该字符作为初始化后屏幕的内容。

#include <string>
using std::string;

class Screen {
    //frined暂缺
    //public别名、构造函数和成员函数
    public:
        using pos = string::size_type;

        Screen() = default;//默认构造函数
        Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht*wd, ' ') { }//2nd
        Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c) { }//3rd
        //重载的get成员函数
        char get() const { return contents[cursor]; }
        char get(pos r, pos c) const { return contents[r * width + c]; }
    //private数据成员
    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        string contents;
};
