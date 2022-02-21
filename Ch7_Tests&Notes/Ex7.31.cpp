//Ex7.31  定义一对类X和Y，其中X包含一个指向Y的指针，而Y包含一个类型为X的对象。

class Y;

class X {
    Y *y = nullptr;
};

class Y {
    X x;
};