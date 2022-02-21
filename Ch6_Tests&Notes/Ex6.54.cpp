//Ex6.54  编写函数的声明，令其接受两个int形参并返回类型也是int；然后声明一个vector对象，令其元素是指向该函数的指针。

int f(int a, int b);
vector<int (*)(int a, int b)> vec;