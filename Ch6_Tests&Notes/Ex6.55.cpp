//Ex6.55  编写4个函数，分别对两个int值执行加、减、乘、除运算；在上一题创建的vector对象中保存指向这些函数的指针。

int add(int a, int b) { return (a + b); }
int subs(int a, int b) { return (a - b); }
int mult(int a, int b) { return (a * b); }
int div(int a, int b) { return ((b != 0) ? (a / b) : 0); }

vec.push_back(add);
vec.push_back(subs);
vec.push_back(mult);
vec.push_back(div);
