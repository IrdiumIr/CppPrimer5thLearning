//Ex7.27  给你自己的Screen类添加move、set 和display函数，通过执行下面的代码检验你的类是否正确。

#include <string>
#include <iostream>//display add
using std::cout;//display add
using std::endl;
using std::ostream; //display add
using std::string;

class Screen {
    //frined暂缺
    public:
        using pos = string::size_type;

        Screen() = default;//默认构造函数
        Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht*wd, ' ') { }//2nd
        Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c) { }//3rd

        char get() const { return contents[cursor]; }
        char get(pos r, pos c) const { return contents[r * width + c]; }

        // new add
        inline Screen &move(pos r, pos c);
        inline Screen &set(char c);
        inline Screen &set(pos r, pos c, char ch);
        Screen &display(ostream &os) { do_display(os); return *this; }
        const Screen &display(ostream &os) const { do_display(os); return *this; } 

        //private数据成员
    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        string contents;
        //new add
        void do_display(ostream &os) const { os << contents; }
};

inline Screen& Screen::set(char c)//inline set 1
{
    contents[cursor] = c;
    return *this;
}

inline Screen& Screen::set(pos r, pos c, char ch)//inline set 2
{
    contents[r*width + c] = ch;
    return *this;
}

inline Screen& Screen::move(pos r, pos c)//inline move
{
    cursor = r*width + c;
    return *this;
}

//test code for 7.27
int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << endl;
    myScreen.display(cout);
    cout << endl;
    return 0;
}