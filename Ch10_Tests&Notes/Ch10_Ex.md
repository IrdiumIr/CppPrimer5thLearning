
### 10.1 头文件`algorithm`中定义了一个名为`count`的函数，它类似`find`，接受一对迭代器和一个值作为参数。`count`返回给定值在序列中出现的次数。编写程序，读取`int`序列存入`vector`中，打印有多少个元素的值等于给定值。

**解：**
```cpp
    #include <iostream>
    #include <vector>
    #include <string>
    #include <list>
    #include <algorithm>

    int main()
    {
        std::vector<int> ivec{1, 2, 3, 4, 1};
        std::list<std::string> slst{"1", "2", "3", "4", "5"};

        std::cout << std::count(ivec.cbegin(), ivec.cend(), 1) << std::endl;
        std::cout << std::count(slst.cbegin(), slst.cend(), "6") << std::endl;
    }
```


### 10.2 重做上一题，但读取`string`序列存入`list`中。

**解：**
* 如`10.1`


### 10.3 用`accumulate`求一个`vector<int>`中元素之和。

**解：**
```cpp
    #include <iostream>
    #include <vector>
    #include <numeric>
    #include <algorithm>

    int main()
    {
        std::vector<int> ivec{1, 2, 3, 4, 5};
        std::vector<double> vec{1.1, 2.2, 3.3};
        std::cout << std::accumulate(ivec.cbegin(), ivec.cend(), 0) << std::endl;
        //std::cout << std::accumulate(vec.cbegin(), vec.cend(), 0) << std::endl;
        std::cout << std::accumulate(vec.cbegin(), vec.cend(), 0.0) << std::endl;
    }
```


### 10.4 假定`v`是一个`vector<double>`，那么调用`accumulate(v.cbegin(),v.cend(),0)`有何错误（如果存在的话）？

**解：**
* 如`10.3`，结果由于加到了初始值`int`上，结果也会是一个`int`而非`double`


### 10.5 在本节对名册（`roster`）调用`equal`的例子中，如果两个名册中保存的都是C风格字符串而不是`string`，会发生什么？

**解：**
* `char []`在实际使用时，实际上保存的是指向数组的指针，因此如果调用`equal`，将比较这两个指针的地址值，而非直接比较两个`cstring`


### 10.6 编写程序，使用`fill_n`将一个序列中的`int`值都设置为0。

**解：**
```cpp
    #include <iostream>
    #include <vector>
    #include <numeric>
    #include <algorithm>

    int main()
    {
        std::vector<int> ivec{1, 2, 3, 4, 5};
        fill_n(ivec.begin(), ivec.size(), 0);
    }
```


### 10.7 下面程序是否有错误？如果有，请改正：
>```cpp
>(a) vector<int> vec; list<int> lst; int i;
>	while (cin >> i)
>		lst.push_back(i);
>	copy(lst.cbegin(), lst.cend(), vec.begin());
>(b) vector<int> vec;
>	vec.reserve(10);
>	fill_n(vec.begin(), 10, 0);

**解：**
* (a)在使用`copy`时，必须保证第二个序列和前一个至少有一样的大小。因此需要提前给`vec`分配空间：`vec.resize(lst.size())`
* (b)`reserve`的是内存空间而非实际`vector`的元素数量，现在的`vec`是一个有10内存空间大小的容器，但是元素数量依然为0。因此要不改为`vec.resize(10)`，添加10个为0的元素；要不使用插入迭代器，改为`fill_n(back_inserter(vec), 10, 0)`


### 10.8 本节提到过，标准库算法不会改变它们所操作的容器的大小。为什么使用`back_inserter`不会使这一断言失效？

**解：**
* `back_inserter`定义在`<iterator>`中，而非标准库算法


### 10.9 实现你自己的`elimDups`。分别在读取输入后、调用`unique`后以及调用`erase`后打印`vector`的内容。

**解：**
* `end_unique`之后的数据有点怪，算了暂时不管(应该也用不上删除的部分)
```cpp
    #include <iostream>
    #include <vector>
    #include <string>
    #include <algorithm>

    auto elimDups(std::vector<std::string> &svec)
    {
        std::sort(svec.begin(), svec.end());
        for (auto p : svec)
            std::cout << p << " ";
        std::cout << std::endl;// sort后的值

        auto end_unique = unique(svec.begin(), svec.end());
        for (auto p : svec)
            std::cout << p << " ";
        std::cout << std::endl;// unique后遍历svec的值--->a b c d  c  
        std::cout << "----------------" << std::endl;
        std::cout << svec.size() << std::endl;// size of svec--->8
        std::cout << end_unique - svec.begin() << std::endl;// size of 删除重复后的svec--->4
        std::cout << svec[4] << "/" << svec[6] <<"/" <<svec[7] << std::endl;// 看下空格处是否真的为空/c/---> 4和7处均为空
        std::cout << svec[4] << std::endl;

        svec.erase(end_unique, svec.end());
        for (auto p : svec)
            std::cout << p << " ";// 删除后遍历svec---> a b c d
        std::cout << std::endl;
    }
    int main()
    {
        std::vector<std::string> svec{"a", "b", "c", "a", "c", "d", "a", "a"};
        elimDups(svec);
    }
```


### 10.10 你认为算法不改变容器大小的原因是什么？

**解：**
* 算法操作的是迭代器而非容器本身；且算法应该和容器类型无关


### 10.11 编写程序，使用`stable_sort`和`isShorter`将传递给你的 `elimDups`版本的`vector`排序。打印`vector`的内容，验证你的程序的正确性。

**解：**
```cpp
    #include <iostream>
    #include <vector>
    #include <string>
    #include <algorithm>

    auto isShorter(const std::string &s1, const std::string &s2)
    {
        return s1.size() < s2.size();
    }
    auto elimDups(std::vector<std::string> &svec)
    {
        std::sort(svec.begin(), svec.end());
        auto end_unique = unique(svec.begin(), svec.end());
        svec.erase(end_unique, svec.end());
    }
    int main()
    {
        std::vector<std::string> svec{"a", "bbbb", "ccc", "a", "ccc", "dd", "a", "a"};
        elimDups(svec);
        std::stable_sort(svec.begin(), svec.end(), isShorter);

        for (auto p : svec)
            std::cout << p << " ";
        std::cout << std::endl;

        return 0;
    }
```


### 10.12 编写名为`compareIsbn`的函数，比较两个`Sales_data`对象的`isbn()`成员。使用这个函数排序一个保存`Sales_data`对象的`vector`。

**解：**
```cpp
    auto compareIsbn(const Sales_data &s1, const Sales_data &s2)
    {
        return s1.isbn().size() < s2.isbn().size();
    }
    int main()
    {
        std::stable_sort(v.begin(), v.end(), compareIsbn);
    }
```


### 10.13 标准库定义了名为`partition`的算法，它接受一个谓词，对容器内容进行划分，使得谓词为`true`的值会排在容器的前半部分，而使得谓词为 `false`的值会排在后半部分。算法返回一个迭代器，指向最后一个使谓词为 `true`的元素之后的位置。编写函数，接受一个`string`，返回一个`bool`值，指出`string`是否有5个或更多字符。使用此函数划分`words`。打印出长度大于等于5的元素。

**解：**
```cpp
    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>
    auto isBigger5(const std::string &s)
    {
        return s.size() > 5;
    }
    int main()
    {
        std::vector<std::string> words{"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa"};
        auto end_true = std::partition(words.begin(), words.end(), isBigger5);
        for (auto iter = words.begin(); iter != end_true; ++iter)
            std::cout << *iter << " ";
        std::cout << std::endl;
    }
```


### 10.14 编写一个`lambda`，接受两个`int`，返回它们的和。

**解：**
```cpp
    auto f = [] (int a, int b) { return a + b; };
```


### 10.15 编写一个`lambda`，捕获它所在函数的`int`，并接受一个`int`参数。`lambda`应该返回捕获的`int`和`int`参数的和。

**解：**
```cpp
    auto func()
    {
        int a = 0;
        auto f = [a] (int i) { return a + i; };
    }
```


### 10.16 使用`lambda`编写你自己版本的`biggies`。

**解：**
```cpp
    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>

    auto elimDups(std::vector<std::string> &svec)
    {
        std::sort(svec.begin(), svec.end());
        auto end_unique = unique(svec.begin(), svec.end());
        svec.erase(end_unique, svec.end());
    }
    auto biggies(std::vector<std::string> &s, std::vector<std::string>::size_type sz)
    {
        elimDups(s);
        std::stable_sort(s.begin(), s.end(), [](const std::string &s1, const std::string &s2)
                        { return s1.size() < s2.size(); });
        auto end_bigger = std::find_if(s.begin(), s.end(), [sz](const std::string &s)
                                    { return s.size() >= sz; });
        auto len = s.end() - end_bigger;
        std::for_each(end_bigger, s.end(), [](const std::string &s)
                    { std::cout << s << " "; });
    }  
    int main()
    {
        std::vector<std::string> words{"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa"};
        biggies(words, 4);
        std::cout << std::endl;
        return 0;
    }
```


### 10.17 重写10.3.1节练习10.12的程序，在对`sort`的调用中使用`lambda`来代替函数`compareIsbn`。

**解：**
```cpp
    std::stable_sort(v.begin(), v, end(), [](const Sales_data &s1, const Sales_data &s2)
              { return s1.isbn().size() < s2.isbn().size(); });
```


### 10.18 重写`biggies`，用`partition`代替`find_if`。我们在10.3.1节练习10.13中介绍了`partition`算法。

**解：**
```cpp
    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>

    auto elimDups(std::vector<std::string> &svec)
    {
        std::sort(svec.begin(), svec.end());
        auto end_unique = unique(svec.begin(), svec.end());
        svec.erase(end_unique, svec.end());
    }
    auto biggies_partition(std::vector<std::string> &s, std::vector<std::string>::size_type sz)
    {
        elimDups(s);
        auto end_big_partition = partition(s.begin(), s.end(), [sz](const std::string &str)
                                        { return str.size() >= sz; });
        std::for_each(s.begin(), end_big_partition, [](const std::string &s)
                    { std::cout << s << " "; });
    }  
    int main()
    {
        std::vector<std::string> words{"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa"};
        biggies_partition(words, 4);
        std::cout << std::endl;
        return 0;
    }
```


### 10.19 用`stable_partition`重写前一题的程序，与`stable_sort`类似，在划分后的序列中维持原有元素的顺序。

**解：**
* 如`10.18`


### 10.20 标准库定义了一个名为`count_if`的算法。类似`find_if`，此函数接受一对迭代器，表示一个输入范围，还接受一个谓词，会对输入范围中每个元素执行。`count_if`返回一个计数值，表示谓词有多少次为真。使用`count_if`重写我们程序中统计有多少单词长度超过6的部分。

**解：**
```cpp
    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>

    int main()
    {
        std::vector<std::string> words{"a", "aa", "aaa", "aaaaaa", "aaaaaaa"};
        auto countNum = std::count_if(words.begin(), words.end(), [](const std::string &s)
                                    { return s.size() > 6; });
        std::cout << "Number of num bigger than 6 is " << countNum << std::endl;
        return 0;
    }
```


### 10.21 编写一个`lambda`，捕获一个局部`int`变量，并递减变量值，直至它变为0。一旦变量变为0，再调用`lambda`应该不再递减变量。`lambda`应该返回一个`bool`值，指出捕获的变量是否为0。

**解：**
```cpp
    int i = 5;
    auto f = [&i]()
    { return (i == 0 ? true : !(i--)); };

    while (!f())
        std::cout << i << " ";
```


### 10.22 重写统计长度小于等于6的单词数量的程序，使用函数代替`lambda`。

**解：**
```cpp
    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>
    #include <functional>
    using namespace std::placeholders;

    auto lessthan6(const std::string &s, std::string::size_type sz)
    {
        return s.size() <= sz;
    }
    int main()
    {
        std::vector<std::string> words{"a", "aa", "aaa", "aaaaaa", "aaaaaaa"};
        auto f = std::count_if(words.begin(), words.end(), std::bind(lessthan6, _1, 6));
        std::cout << f << std::endl;
        return 0;
    }
```


### 10.23 `bind`接受几个参数？

**解：**
* `bind`接受`calllable`.`_1`.`_2`.······`_n` 共`n + 1`个参数


### 10.24 给定一个`string`，使用`bind`和`check_size`在一个`int`的`vector`中查找第一个大于`string`长度的值。

**解：**
```cpp
    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>
    #include <functional>
    using namespace std::placeholders;

    auto check_size(const std::string &s, std::string::size_type sz)
    {
        return s.size() < sz;
    }
    int main()
    {
        std::string s{"123"};// size=3
        std::vector<int> ivec{0, 1, 2, 3, 4, 5, 6};
        auto f = std::find_if(ivec.begin(), ivec.end(), bind(check_size, s, _1));
        if (f != ivec.end())
            std::cout << *f << std::endl;
        return 0;
    }
```


### 10.25 在10.3.2节的练习中，编写了一个使用`partition`的`biggies`版本。使用`check_size`和`bind`重写此函数。

**解：**
```cpp
    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>
    #include <functional>
    using namespace std::placeholders;

    auto elimDups(std::vector<std::string> &svec)
    {
        std::sort(svec.begin(), svec.end());
        auto end_unique = unique(svec.begin(), svec.end());
        svec.erase(end_unique, svec.end());
    }
    auto check_size(const std::string &s, std::string::size_type sz)
    {
        return s.size() >= sz;
    }
    auto biggies(std::vector<std::string> &svec, std::string::size_type sz)
    {
        elimDups(svec);
        auto f = std::stable_partition(svec.begin(), svec.end(), bind(check_size, _1, sz));
        for_each(svec.begin(), f, [](const std::string &s)
                { std::cout << s << " "; });
    }
    int main()
    {
        std::vector<std::string> words{"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa"};
        biggies(words, 4);
        std::cout << std::endl;
        return 0;
    }
```


### 10.26 解释三种插入迭代器的不同之处。

**解：**
* 如`Notes_10.4.1`


### 10.27 除了`unique`之外，标准库还定义了名为`unique_copy`的函数，它接受第三个迭代器，表示拷贝不重复元素的目的位置。编写一个程序，使用 `unique_copy`将一个`vector`中不重复的元素拷贝到一个初始化为空的`list`中。

**解：**
```cpp
    #include <iostream>
    #include <list>
    #include <vector>
    #include <algorithm>
    #include <iterator>

    int main()
    {
        std::vector<int> ivec{0, 1, 1, 2, 2, 3};
        std::list<int> ilst;
        std::unique_copy(ivec.begin(), ivec.end(), back_inserter(ilst));
        std::for_each(ilst.cbegin(), ilst.cend(), [](const int &s)
                    { std::cout << s << " "; });
        std::cout << std::endl;
        return 0;
    }
```


### 10.28 一个`vector`中保存 1 到 9，将其拷贝到三个其他容器中。分别使用`inserter`、`back_inserter`和`front_inserter`将元素添加到三个容器中。对每种`inserter`，估计输出序列是怎样的，运行程序验证你的估计是否正确。

**解：**
```cpp
    #include <iostream>
    #include <list>
    #include <vector>
    #include <algorithm>
    #include <iterator>

    int main()
    {
        std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::list<int> lst1, lst2, lst3;
        copy(ivec.cbegin(), ivec.cend(), inserter(lst1, lst1.begin()));
        copy(ivec.cbegin(), ivec.cend(), back_inserter(lst2));
        copy(ivec.cbegin(), ivec.cend(), front_inserter(lst3));
        std::for_each(lst1.cbegin(), lst1.cend(), [](const int &s)
                    { std::cout << s << " "; });
        std::cout << std::endl;
        std::for_each(lst2.cbegin(), lst2.cend(), [](const int &s)
                    { std::cout << s << " "; });
        std::cout << std::endl;
        std::for_each(lst3.cbegin(), lst3.cend(), [](const int &s)
                    { std::cout << s << " "; });
        std::cout << std::endl;
        return 0;
    }
```


### 10.29 编写程序，使用流迭代器读取一个文本文件，存入一个`vector`中的`string`里。

**解：**
```cpp
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <vector>
    #include <iterator>

    int main()
    {
        std::ifstream ifs("addr/data.txt");
        std::vector<std::string> svec;
        std::istream_iterator<std::string> in(ifs), eof;

        while (in != eof)
            svec.push_back(*in++);
    }
```


### 10.30 使用流迭代器、`sort`和`copy`从标准输入读取一个整数序列，将其排序，并将结果写到标准输出。

**解：**
```cpp
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include <iterator>

    int main()
    {
        std::vector<int> ivec;
        std::istream_iterator<int> in(std::cin), eof;
        std::ostream_iterator<int> out(std::cout, " ");
        // while (in != eof)
        //     ivec.push_back(*in++);
        // 要用copy
        copy(in, eof, back_inserter(ivec));
        sort(ivec.begin(), ivec.end());
        copy(ivec.begin(), ivec.end(), out);
        std::cout << std::endl;
        return 0;
    }
```


### 10.31 修改前一题的程序，使其只打印不重复的元素。你的程序应该使用`unique_copy`。

**解：**
```cpp
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include <iterator>

    int main()
    {
        std::vector<int> ivec;
        std::istream_iterator<int> in(std::cin), eof;
        std::ostream_iterator<int> out(std::cout, " ");
        // while (in != eof)
        //     ivec.push_back(*in++);
        // 要用copy
        copy(in, eof, back_inserter(ivec));
        sort(ivec.begin(), ivec.end());
        // copy(ivec.begin(), ivec.end(), out);
        std::unique_copy(ivec.begin(), ivec.end(), out);
        std::cout << std::endl;
        return 0;
    }
```


### 10.32 重写1.6节中的书店程序，使用一个`vector`保存交易记录，使用不同算法完成处理。使用`sort`和10.3.1节中的`compareIsbn`函数来排序交易记录，然后使用`find`和`accumulate`求和。

**解：**
* too far away...NULL


### 10.33 编写程序，接受三个参数：一个输入文件和两个输出文件的文件名。输入文件保存的应该是整数。使用`istream_iterator`读取输入文件。使用`ostream_iterator`将奇数写入第一个输入文件，每个值后面都跟一个空格。将偶数写入第二个输出文件，每个值都独占一行。

**解：**
```cpp
    #include <iostream>
    #include <fstream>
    #include <iterator>
    #include <algorithm>
    int main()
    {
        std::ifstream ifs;
        std::ofstream ofs1, ofs2;

        std::istream_iterator<int> in(ifs), eof;
        std::ostream_iterator<int> out1(ofs1, " "), out2(ofs2, "\n");// 奇数1空格，偶数2换行
        while (in != eof)
        {
            if (*in % 2)
                *out1++ = *in++;
            else
                *out2++ = *in++;
        }
        // std::for_each(in, eof, [&out1, &out2](const int i)
        // {
        // 	*(i & 0x1 ? out1 : out2)++ = i;
        // });
        // 简洁解法
        return 0;
    }
```


### 10.34 使用`reverse_iterator`逆序打印一个`vector`。

**解：**
```cpp
    #include <iostream>
    #include <iterator>
    #include <vector>
    int main()
    {
        std::vector<int> ivec{1, 2, 3, 4, 5};
        for (auto it = ivec.crbegin(); it != ivec.crend(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        return 0;
    }
```


### 10.35 使用普通迭代器逆序打印一个`vector`。

**解：**
```cpp
    #include <iostream>
    #include <iterator>
    #include <vector>
    int main()
    {
        std::vector<int> ivec{1, 2, 3, 4, 5};
        for (auto it = ivec.cend(); it != ivec.cbegin(); )
            std::cout << *(--it) << " ";
        std::cout << std::endl;
    }
```


### 10.36 使用`find`在一个`int`的`list`中查找最后一个值为0的元素。

**解：**
```cpp
    #include <iostream>
    #include <iterator>
    #include <list>
    #include <algorithm>

    int main()
    {
        std::list<int> lst{1, 2, 0, 3, 4, 0, 5};
        auto it = std::find(lst.crbegin(), lst.crend(), 0);
        auto it1 = it.base();
        std::cout << distance(lst.cbegin(), it1);
    }
```


### 10.37 给定一个包含10个元素的`vector`，将位置3到7之间的元素按逆序拷贝到一个`list`中。

**解：**
```cpp
    #include <iostream>
    #include <iterator>
    #include <list>
    #include <algorithm>
    #include <vector>

    int main()
    {
        std::vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};// 3-7分别为34567
        std::list<int> lst;
        copy(ivec.rbegin() + 2, ivec.rbegin() + 7, back_inserter(lst));
        for (auto i : lst)
            std::cout << i << " ";
    }
```


### 10.38 列出5个迭代器类别，以及每类迭代器所支持的操作。

**解：**
* 如`10.5`


### 10.39 `list`上的迭代器属于哪类？`vector`呢？

**解：**
* `list`上的迭代器属于双向迭代器
* `vector`上的迭代器属于随机访问迭代器


### 10.40 你认为`copy`要求哪类迭代器？`reverse`和`unique`呢？

**解：**
* `copy`前两个参数需要输入迭代器，最后的目标位置需要输出迭代器
* `reverse`需要双向迭代器
* `unique`需要随机访问迭代器


### 10.41 仅根据算法和参数的名字，描述下面每个标准库算法执行什么操作：
>```cpp
>replace(beg, end, old_val, new_val);
>replace_if(beg, end, pred, new_val);
>replace_copy(beg, end, dest, old_val, new_val);
>replace_copy_if(beg, end, dest, pred, new_val);

**解：**
* `replace`在前两个迭代器范围内用`new_val`替代`old_val`
* `replace_if`在前两个迭代器范围内对符合`pred`的对象替换为`new_val`
* `replace_copy`将前两个迭代器范围内的元素复制到`dest`位置，并将等于`old_val`的值替换为`new_val`
* `repalce_copy_if`将前两个迭代器范围内的元素复制到`dest`位置，并将符合`pred`的对象值替换为`new_val`


### 10.42 使用`list`代替`vector`重新实现10.2.3节中的去除重复单词的程序。

**解：**
```cpp
    #include <iostream>
    #include <iterator>
    #include <list>
    #include <algorithm>
    #include <string>

    int main()
    {
        std::list<std::string> slst{"a", "aa", "aaa", "aaaa", "aaa", "a"};
        slst.sort();
        slst.unique();
        std::for_each(slst.begin(), slst.end(), [](const std::string &s)
                    { std::cout << s << " "; });
        std::cout << std::endl;
    }
```