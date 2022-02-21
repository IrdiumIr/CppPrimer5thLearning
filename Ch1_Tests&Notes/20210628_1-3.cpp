#include <iostream>

int main()
{
    std::cout << "/*";
    std::cout << "*/";
    //std::cout << /* "*/" */;  此句出错，可按如下修改：
    std::cout << /* "*/" */";  //从每个/*开始到下一个*/之内的内容都被注释掉
    std::cout << /* "*/" /* "/*" */;
    return 0;
}