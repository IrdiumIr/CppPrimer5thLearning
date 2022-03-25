
### 9.1 对于下面的程序任务，`vector`、`deque`和`list`哪种容器最为适合？解释理由。如果没有优劣，也请解释理由。
>(a) 读取固定数量的单词，将它们按字典序插入到容器中。我们将在下一章中看到，关联容器更适合这个问题。
(b) 读取未知数量的单词，总是将单词插入到末尾。删除操作在头部进行。
(c) 从一个文件读取未知数量的整数。将这些数排序，然后将它们打印到标准输出。

**解：**
* (a).使用`list`。在按照非读取顺序插入时，另外两个只在头尾插入性能较好。
* (b).使用`deque`。因为只是在头尾进行操作，而非中间。
* (c).使用`vector`。无需进行插入删除操作。排序可使用`sort`。


### 9.2 定义一个`list`对象，其元素类型是`int`的`deque`。

**解：**
```cpp
    std::list<std::deque<int>> list1;
```


### 9.3 构成迭代器范围的迭代器有何限制？

**解：**
* 1.指向同一个容器，`end`可指向尾后；
* 2.`begin`≤`end`


### 9.4 编写函数，接受一对指向`vector<int>`的迭代器和一个`int`值。在两个迭代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到。

**解：**
```cpp
    bool isFind(vector<int>::const_iterator begin, vector<int>::const_iterator end, int i)
    {
        while (begin != end)
        {
            if (*begin == i)
                  return true;
            ++begin;
        }
        return false;
    }
```


### 9.5 重写上一题的函数，返回一个迭代器指向找到的元素。注意，程序必须处理未找到给定值的情况。

**解：**
```cpp
    vector<int>::const_iterator find(vector<int>::const_iterator begin, vector<int>::const_iterator end, int i)
    {
        while (begin != end)
        {
            if (*begin == i)
                  return begin;
            ++begin;
        }
        return end;
    }
```


### 9.6 下面的程序有何错误？你应该如何修改它？
>```cpp
>list<int> lst1;
>list<int>::iterator iter1 = lst1.begin(),
>					iter2 = lst1.end();
>while (iter1 < iter2) /* ... */`

**解：**
* 将最后使用迭代器的部分`while (iter1 < iter2)`改为`while(iter1 != iter2)`，迭代器的`<`和`>`目前只在`vector`和`string`中出现


### 9.7 为了索引`int`的`vector`中的元素，应该使用什么类型？

**解：**
* 应当使用`vector<int>::size_type`类型


### 9.8 为了读取`string`的`list`中的元素，应该使用什么类型？如果写入`list`，又应该使用什么类型？

**解：**
* 1.应当使用`list<string>::const_iterator`类型
* 2.应当使用`list<string>::iterator`类型


### 9.9 `begin`和`cbegin`两个函数有什么不同？

**解：**
* `begin`是非`const`的，返回的类型是`iterator`普通迭代器
* `cbegin`是`const`的，返回的类型是`const_iterator`常量迭代器


### 9.10 下面4个对象分别是什么类型？
>```cpp
>vector<int> v1;
>const vector<int> v2;
>auto it1 = v1.begin(), it2 = v2.begin();
>auto it3 = v1.cbegin(), it4 = v2.cbegin();

**解：**
* `it1`的类型是`vector<int>::iterator`
* `it2`.`it3`.`it4`的类型是`vector<int>::const_iterator`


### 9.11 对6种创建和初始化`vector`对象的方法，每一种都给出一个实例。解释每个`vector`包含什么值。

**解：**
```cpp
    vector<int> vec;//  vec为空
    vector<int> vec(n);//  vec有n个0
    vector<int> vec(n, t);//  vec有n个t
    vector<int> vec(vec1);//  vec是vec1的拷贝
    vector<int> vec{v1, v2, v3};//  vec的初始值是v1, v2, v3
    vector<int> vec(vec1.begin(), vec1.end());//  vec拷贝了vec1从begin到end的元素
```


### 9.12 对于接受一个容器创建其拷贝的构造函数，和接受两个迭代器创建拷贝的构造函数，解释它们的不同。

**解：**
* 如**Ch9_Notes_9.2.4.(3)**：前者需要类型都匹配；而使用迭代器只需元素可以相互转换


### 9.13 如何从一个`list<int>`初始化一个`vector<double>`？从一个`vector<int>`又该如何创建？编写代码验证你的答案。

**解：**
* 由于至少有一个类型不匹配，都使用迭代器进行初始化
```cpp
    list<int> list1(3,1);
    vector<int> vec1(3,1);

    vector<double> vec2(list1.begin(), list1.end());
    vector<double> vec3(vec1.begin(),list1.end());
```


### 9.14 编写程序，将一个`list`中的`char *`指针元素赋值给一个`vector`中的`string`。

**解：**
```cpp
    list<const char *> lst{"dongqi", "irdium"};
    vector<string> vec;
    //使用assign赋值
    vec.assign(lst.cbegin(), lst.cend());
```


### 9.15 编写程序，判定两个`vector<int>`是否相等。

**解：**
```cpp
    vector<int> vec1{1,2,3};
    vector<int> vec2{1,2,3};
    vector<int> vec3{1,2};
    //进行比较
    cout << (vec1 == vec2 ? "true" : "false") <<endl;//  true
    cout << (vec1 == vec3 ? "true" : "false") <<endl;//  false
```


### 9.16 重写上一题的程序，比较一个`list<int>`中的元素和一个`vector<int>`中的元素。

**解：**
```cpp
    list<int> lst{1,2,3};
    vector<int> vec1{1,2,3};
    vector<int> vec2{1,2};
    //只有完全相同类型才能直接进行比较，因此把list赋值给一个新的vector
    cout << (vector<int>(lst.begin(), lst.end()) == vec1 ? "true" : "false") <<endl;//  true
    cout << (vector<int>(lst.begin(), lst.end()) == vec2 ? "true" : "false") <<endl;//  false
```


### 9.17 假定`c1`和`c2`是两个容器，下面的比较操作有何限制？
>```cpp
>if (c1 < c2)

**解：**
* `c1`和`c2`必须类型完全相同
* `c1`和`c2`中的元素需要支持`<`的运算符


### 9.18 编写程序，从标准输入读取`string`序列，存入一个`deque`中。编写一个循环，用迭代器打印`deque`中的元素。

**解：**
```cpp
    #include <iostream>
    #include <string>
    #include <deque>

    int main()
    {
        std::string str;
        std::deque<std::string> seq;
        while (std::cin >> str)
        {
            seq.emplace_back(str);
        }
        for (auto iter = seq.cbegin(); iter != seq.cend(); ++iter)
        {
            std::cout << *iter << std::endl;
        }
    }
```


### 9.19 重写上一题的程序，用`list`替代`deque`。列出程序要做出哪些改变。

**解：**
* `list`和`deque`都支持`emplace_back`操作，因此只需要把声明改为`std::list<std::string> lst;`即可


### 9.20 编写程序，从一个`list<int>`拷贝元素到两个`deque`中。值为偶数的所有元素都拷贝到一个`deque`中，而奇数值元素都拷贝到另一个`deque`中。

**解：**
```cpp
    #include <iostream>
    #include <list>
    #include <deque>

    int main()
    {
        std::list<int> lst{ 1, 2, 3, 4, 5 };
        std::deque<int> seq1, seq2;
        for (auto p : lst)
        {
            if (p % 2 == 0)
                seq1.push_back(p);//  偶数seq
            else
                seq2.push_back(p);//  奇数seq
        }
    }
```


### 9.21 如果我们将第308页中使用`insert`返回值将元素添加到`list`中的循环程序改写为将元素插入到`vector`中，分析循环将如何工作。

**解：**
* `insert`属于通用性的容器操作，虽然`vector`不支持`push_front`，但是循环使用`insert`插入开头的原理是一样的


### 9.22 假定`iv`是一个`int`的`vector`，下面的程序存在什么错误？你将如何修改？
>```cpp
>vector<int>::iterator iter = iv.begin(),
>					  mid = iv.begin() + iv.size() / 2;
>while (iter != mid)
>	if (*iter == some_val)
>		iv.insert(iter, 2 * some_val);

**解：**
* `iter != mid`的条件永远生效，循环是死循环
* 在使用`insert`插入元素改变了`vector`的大小后，原来的迭代器会失效
```cpp
    while (iter != mid)
    {
        if (*iter == some_val)
	    {
		    iter = iv.insert(iter, 2 * some_val);
		    ++iter;
        }
	    ++iter;
    }
```


### 9.23 在本节第一个程序中，若`c.size()`为1，则`val`、`val2`、`val3`和`val4`的值会是什么？

**解：**
* 值都是容器内仅有的那个元素的值


### 9.24 编写程序，分别使用`at`、下标运算符、`front`和`begin`提取一个`vector`中的第一个元素。在一个空`vector`上测试你的程序。

**解：**
```cpp
    #include <iostream>
    #include <vector>

    int main()
    {
        std::vector<int> vec;
        std::cout << v.at(0);
        std::cout << v[0];
        std::cout << v.front();
        std::cout << *(v.begin());
    }
```


### 9.25 对于第312页中删除一个范围内的元素的程序，如果`elem1`与`elem2`相等会发生什么？如果`elem2`是尾后迭代器，或者`elem1`和`elem2`皆为尾后迭代器，又会发生什么？

**解：**
* 如果`elem=elem2`，不会删除元素
* 如果`elem2`是尾后迭代器，从`elem1`到容器尾的元素都会被删除
* 如果都是尾后迭代器，也不会删除元素


### 9.26 使用下面代码定义的`ia`，将`ia`拷贝到一个`vector`和一个`list`中。使用单迭代器版本的`erase`从`list`中删除奇数元素，从`vector`中删除偶数元素。
>```cpp
>int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

**解：**
```cpp
    #include <iostream>
    #include <vector>
    #include <list>

    int main()
    {
        int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
        std::vector<int> vec(begin(ia), end(ia));
        list<int> lst(vec.begin(), vec.end());

        while (lst.begin() != lst.end())
        {
            if (*(lst.begin()) % 2)//  删除奇数
                lst.begin() = lst.erase(lst.begin());
            else
                ++lst.begin();
        }

        while (vec.begin() != vec.end())
        {
            if (!(*(vec.begin()) % 2))//  删除偶数
                vec.begin() = vec.erase(vec.begin());
            else
                ++vec.begin();
        }
    }
```


### 9.27 编写程序，查找并删除`forward_list<int>`中的奇数元素。

**解：**
```cpp
    #include <iostream>
    #include <forward_list>
    #include <vector>

    int main()
    {
        std::forward_list<int> flst{ 0, 1, 2, 3, 4 };
        std::vector<int> vec;//  储存查找到的奇数
        auto prev = flst.before_begin();
        auto curr = flst.begin();

        while (curr != flst.end())
        {
            if (*curr % 2)
            {
                vec.push_back(*curr);//  查找奇数并储存
                curr = flst.erase_after(prev);//  删除奇数
            }
            else
            {
                prev = curr;
                ++curr;
            }
        }
    }
```


### 9.28 编写函数，接受一个`forward_list<string>`和两个`string`共三个参数。函数应在链表中查找第一个`string`，并将第二个`string`插入到紧接着第一个`string`之后的位置。若第一个`string`未在链表中，则将第二个`string`插入到链表末尾。

**解：**
```cpp
    void func(std::forward_lit<std::string> &flst, const std::string &s1, const std::string &s2)
        {
            bool flag = false;//  判断是否存在
            auto prev = flst.before_begin();
            auto curr = flst.begin();
            while (curr != flst.end())
            {
                if (*curr == s1)
                {
                    flst.insert_after(curr, s2);
                    flag = true;
                }
                prev = curr;
                ++curr;
            }
            if (flag == false)
                flst.insert_after(prev, s2);
        }
```


### 9.29 假定`vec`包含25个元素，那么`vec.resize(100)`会做什么？如果接下来调用`vec.resize(10)`会做什么？

**解：**
* 添加75个元素到vec末尾，进行初始化
* 从未尾删除90个元素


### 9.30 接受单个参数的`resize`版本对元素类型有什么限制（如果有的话）？

**解：**
* 元素可以进行值初始化，或者类型提供了一个默认构造函数


### 9.31 第316页中删除偶数值元素并复制奇数值元素的程序不能用于`list`或`forward_list`。为什么？修改程序，使之也能用于这些类型。

**解：**
* 对`list`，`iter += 2`不能实现复合赋值：因此可改为`++iter;++iter;`
* 对`forward_list`，在插入和删除元素的时候，需要使用其专属的`insert_after`和`erase_after`，且递增同样要写两次


### 9.32 在第316页的程序中，像下面语句这样调用`insert`是否合法？如果不合法，为什么？
>```cpp
>iter = vi.insert(iter, *iter++);
**解：**
* `*iter++`的语法没问题，但是在函数内参数的求值顺序实际上是不确定的，因此并不能确定是用`iter`还是`++iter`的值


### 9.33 在本节最后一个例子中，如果不将`insert`的结果赋予`begin`，将会发生什么？编写程序，去掉此赋值语句，验证你的答案。

**解：**
* `begin`将会失效


### 9.34 假定`vi`是一个保存`int`的容器，其中有偶数值也有奇数值，分析下面循环的行为，然后编写程序验证你的分析是否正确。
>```cpp
>iter = vi.begin();
>while (iter != vi.end())
>	if (*iter % 2)
>		iter = vi.insert(iter, *iter);
>	++iter;
**解：**
* `++iter`是在while循环之外的部分，因此这个循环将进入死循环


### 9.35 解释一个`vector`的`capacity`和`size`有何区别。

**解：**
* `size`只是`vector`内已保存的元素数量
* `capacity`指不重新分配内存空间的情况下，这个`vector`的内存空间大小


### 9.36 一个容器的`capacity`可能小于它的`size`吗？

**解：**
* 不可能


### 9.37 为什么`list`或`array`没有`capacity`成员函数？

**解：**
* `list`是链表，存储和`vector`是存储在连续内存空间中不同，链接靠前后的指针实现
* `array`不允许改变大小，有本身固定大小\


### 9.38 编写程序，探究在你的标准实现中，`vector`是如何增长的。

**解：**
```cpp
    #include <iostream>
    #include <string>
    #include <vector>

    int main()
    {
        vector<int> ivec;
        for (auto i = 0; i != 20; ++i)
        {
            std::cout << "capacity: " << ivec.capacity() << "  size: " << ivec.size() << std::endl;
		    ivec.push_back(i);
        }
    }
```


### 9.39 解释下面程序片段做了什么：
>```cpp
>vector<string> svec;
>svec.reserve(1024);
>string word;
>while (cin >> word)
>	svec.push_back(word);
>svec.resize(svec.size() + svec.size() / 2);

**解：**
* 首先将`svec`的内存空间分配为1024，接下来通过循环反复输入字符串到`svec`中，当循环结束后，将`svec`的空间扩充为1.5倍，剩余空间用`string`的初始值填充


### 9.40 如果上一题的程序读入了256个词，在`resize`之后容器的`capacity`可能是多少？如果读入了512个、1000个、或1048个呢？

**解：**
* 256和512词的情况下，`capacity`为1024；1000和1500扩容后均大于1024，因此`capacity`会大于1024


### 9.41 编写程序，从一个`vector<char>`初始化一个`string`。

**解：**
```cpp
    string str(vec.cbegin(), vec.cend());
```


### 9.42 假定你希望每次读取一个字符存入一个`string`中，而且知道最少需要读取100个字符，应该如何提高程序的性能？

**解：**
* 提前分配多余空间以避免实际读取时再分配
```cpp
    str.reserve(200);
```


### 9.43 编写一个函数，接受三个`string`参数是`s`、`oldVal`和`newVal`。使用迭代器及`insert`和`erase`函数将`s`中所有`oldVal`替换为`newVal`。测试你的程序，用它替换通用的简写形式，如，将"tho"替换为"though",将"thru"替换为"through"。

**解：**
```cpp
    auto func(string &s, const string &oldVal, const string &newVal)
    {
        for (auto p = s.begin(); p != (s.end() - oldVal.size()); )
        {
            if (string(p, p + oldVal.size()) == oldVal)
            {
                p = s.erase(p, p + oldVal.size());//  删去原有字符，返回删后迭代器
                p = s.insert(p, newVal.begin(), newVal.end());//  插入新字符，返回新插入第一个
                p += newVal.size();//  迭代器移动到下一处
            }
            else
                ++p;
        }
    }
```


### 9.44 重写上一题的函数，这次使用一个下标和`replace`。

**解：**
```cpp
    auto func(string &s, const string &oldVal, const string &newVal)
    {
        for (size_t p = 0; p != (s.size() - oldVal.size()); )
        {
            if (s.substr(p, oldVal.size()) == oldVal)
            {
                s.replace(p, oldVal.size(), newVal);
                p += newVal.size();
            }
            else
                ++p;
        }
    }
```


### 9.45 编写一个函数，接受一个表示名字的`string`参数和两个分别表示前缀（如"Mr."或"Mrs."）和后缀（如"Jr."或"III"）的字符串。使用迭代器及`insert`和`append`函数将前缀和后缀添加到给定的名字中，将生成的新`string`返回。

**解：**
```cpp
    auto func(string &name, const string &head, const string &end)
    {
        name.insert(name.begin(), head.cbegin(), head.cend());
        name.append(end);
        return name;
    }
```


### 9.46 重写上一题的函数，这次使用位置和长度来管理`string`，并只使用`insert`。

**解：**
```cpp
    auto func(string &name, const string &head, const string &end)
    {
        name.insert(0, head);
        name.insert(name.size(), end);
        return name;
    }
```


### 9.47 编写程序，首先查找`string`"ab2c3d7R4E6"中每个数字字符，然后查找其中每个字母字符。编写两个版本的程序，第一个要使用`find_first_of`，第二个要使用`find_first_not_of`。

**解：**
```cpp
    #include <iostream>
    #include <string>

    int main()
    {
        std::string numbers("0123456789");//  数字string
        std::string alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");//  字母string，考虑大小写
        std::string s("ab2c3d7R4E6");

        std::cout << "numeric characters: ";//  find_first_of
        for (std::string::size_type pos = 0; (pos = s.find_first_of(numbers, pos)) != std::string::npos; ++pos)
        {
            std::cout << s[pos] << " ";
        }

        std::cout << "\nalphabetic characters: ";//  find_first_not_of
        for (std::string::size_type pos = 0; (pos = s.find_first_not_of(numbers, pos)) != std::string::npos; ++pos)
        {
            std::cout << s[pos] << " ";
        }
        return 0;
    }
```


### 9.48 假定`name`和`numbers`的定义如325页所示，`numbers.find(name)`返回什么？

**解：**
* 返回`std::string::npos`


### 9.49 如果一个字母延伸到中线之上，如d或f，则称其有上出头部分（`ascender`）。如果一个字母延伸到中线之下，如p或g，则称其有下出头部分（`descender`）。编写程序，读入一个单词文件，输出最长的既不包含上出头部分，也不包含下出头部分的单词。

**解：**
```cpp
    # include <iostream>
    # include <string>
    # include <fstream>

    auto func(std::ifstream &ifs)
    {
        std::string s, word;
        std::string::size_type length = 0;
        while (ifs >> s)
        {
            if (s.find_first_not_of("acemnorsuvwxz") != std::string::npos)//  如果有上下头字母，则跳出
                continue;
            if (length < s.size())
            {
                length = s.size();
                word = s;
            }//  更新迭代最长者
        }
        std::cout << "the longest word is : " << word << " , and the length is : " << length << std::endl;
    }

    int main()
    {
        std::ifstream ifs("../address/text.txt");
        if (!ifs)
        {
            std::cerr << "cannot open file ! " << std::endl;
            return -1;
        }
        func(ifs);
        return 0;
    }
```


### 9.50 编写程序处理一个`vector<string>`，其元素都表示整型值。计算`vector`中所有元素之和。修改程序，使之计算表示浮点值的`string`之和。

**解：**
```cpp
    # include <iostream>
    # include <vector>
    # include <string>

    int main()
    {
        std::vector<std::string> str{"1", "2.3", "4"};
        int sum1 = 0;
        float sum2 = 0.0;
        for (auto i : str)
        {
            sum1 += std::stoi(i);
        }
        for (auto f : str)
        {
            sum2 += std::stof(f);
        }
        std::cout << sum1 << std::endl;
        std::cout << sum2 << std::endl;
        return 0;
    }
```


### 9.51 设计一个类，它有三个`unsigned`成员，分别表示年、月和日。为其编写构造函数，接受一个表示日期的`string`参数。你的构造函数应该能处理不同的数据格式，如January 1,1900、1/1/1990、Jan 1 1900 等。

**解：**
```cpp
    # include <iostream>
    # include <vector>
    # include <string>

    class Date
    {
    private:
        unsigned year = 0;
        unsigned month = 0;
        unsigned day = 0;
        unsigned pattern = 0;//  根据格式分配处理方法的signal
    public:
        Date() = default;
        Date(const std::string &s)
        {
            if (s.find_first_of("/") != std::string::npos)
                pattern = 1;//  1/1/1990
            else if (s.find_first_of(",") != std::string::npos)
                pattern = 2;//  January 1,1990
            else
                pattern = 3;//  Jan 1 1990

            switch (pattern)
            {
                case 1:
                    year = stoi(s.substr(s.find_last_of("/") + 1, 4));
                    month = stoi(s.substr(s.find_first_of("/") + 1, s.find_last_of("/") - s.find_first_of("/")));
                    day = stoi(s.substr(0, s.find_first_of("/") - 0));
                    break;
                case 2:
                    if (s.find("Jan") != std::string::npos)
                        month = 1;
                    if (s.find("Feb") != std::string::npos)
                        month = 2;
                    if (s.find("Mar") != std::string::npos)
                        month = 3;
                    //...后续类似
                    day = stoi(s.substr(s.find_first_of("0123456789"), s.find_first_of(",") - s.find_first_of("0123456789")));
                    year = stoi(s.substr(s.find_first_of(",") + 1, 4));
                    break;
                case 3:
                    if (s.find("Jan") != std::string::npos)
                        month = 1;
                    if (s.find("Feb") != std::string::npos)
                        month = 2;
                    //...后续类似
                    day = stoi(s.substr(s.find_first_of("0123456789"), s.find_last_of(" ") - s.find_first_of("0123456789")));
                    year = stoi(s.substr(s.find_last_of(" ") + 1, 4));
                    break;
            }
        }
        void printOut()
        {
            std::cout << "year : " << year << " ,month : " << month << " ,day : " << day << std::endl;
        }
    };
```


### 9.52 使用`stack`处理括号化的表达式。当你看到一个左括号，将其记录下来。当你在一个左括号之后看到一个右括号，从`stack`中`pop`对象，直至遇到左括号，将左括号也一起弹出栈。然后将一个值（括号内的运算结果）`push`到栈中，表示一个括号化的（子）表达式已经处理完毕，被其运算结果所替代。

**解：**
* 力有不逮 关于中缀转后缀部分后续待更新 继续往后看ing
```cpp
    #include <stack>
    #include <string>
    #include <iostream>
    #include <deque>

    int main()
    {
        std::string expression("1+(2-3)*4+(5-1)*2");
        std::stack<char> stk;
        std::deque<char> deq;

        std::stack<int> num;
        std::stack<char> signal;

        std::string::iterator iter = expression.begin();
        while (iter != expression.end())
        {
            if (*iter != ')')
                stk.push(*iter);//  依次入栈
            else//  读到右侧)
            {
                while (stk.top() != '(')//  读到左侧(前
                {
                    deq.push_front(stk.top());//  deq:2 - 3(first loop)
                    stk.pop();
                }

                // calculate '$'
                for (auto i = 0; i != deq.size(); ++i)
                {
                    if (deq[i] >= '0' && deq[i] <= '9')
                        num.push((deq[i] - '0'));//  char转数字
                    else
                        signal.push(deq[i]);
                }//  数字和计算符分开成两个stack    and then?

                if (stk.top() == '(')
                {
                    stk.pop();
                    stk.push('$'); //  插入结果
                }
            }
            ++iter;
        }
    }
```