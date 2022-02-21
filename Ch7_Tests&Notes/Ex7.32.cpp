//Ex7.32  定义你自己的Screen和Window_mgr，其中clear是Window_mgr的成员，是Screen的友元。

//先定义Window_mgr，声明clear；再定义Screen，声明clear友元；最后定义clear(需要用到Screen的成员)
// class Screen copy Ex7.27
#include <vector>//Window_mgr add
#include <iostream>
#include <string>

using std::vector; using std::cout; using std::ostream;  using std::string;

class Window_mgr {
    public:
        using ScreenIndex = vector<Screen>::size_type;
        void clear(ScreenIndex);//声明clear
    private:
        vector<Screen> screens;
};

class Screen { //Ex7.27
    
    friend void Window_mgr::clear(ScreenIndex);//友元，需标识window_mgr::
    
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

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

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
