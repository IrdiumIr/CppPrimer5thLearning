
### 11.1 描述`map`和`vector`的不同。

**解：**
* `map`也是有顺序的，但是是关联容器；定义了一组键值对来保存数据，通过访问关键字来得到相应的值；`vector`则是通过下标/迭代器来对容器中的元素进行顺序访问


### 11.2 分别给出最适合使用`list`、`vector`、`deque`、`map`以及`set`的例子。

**解：**
* `list`适合在链表中任意位置需要多次插入删除元素
* `vector`适合在容器中任意位置访问对象
* `deque`适合在队列头尾插入删除元素
* `map`适合保存一组键值对，对于某类元素的数据进行统计
* `set`适合对有序不重复的元素进行处理


### 11.3 编写你自己的单词计数程序。

**解：**
```cpp
    #include <iostream>
    #include <vector>
    #include <map>
    #include <string>

    int main()
    {
        std::map<std::string, size_t> word_count;
        std::string word;
        while (std::cin >> word)
            ++word_count[word];
        for (auto i : word_count)
            std::cout << i.first << " " << i.second << std::endl;
    }
```


### 11.4 扩展你的程序，忽略大小写和标点。例如，"example."、"example,"和"Example"应该递增相同的计数器。

**解：**
```cpp
    #include <algorithm>
    #include <iostream>
    #include <map>
    #include <string>
    #include <cctype>

    auto change_to_same(std::string &s)// 将输入的string先进行归一化，而非采用multi多元素对应同一关键字
    {
        for (auto &i : s)
            i = tolower(i);
        auto remove_first = remove_if(s.begin(), s.end(), ispunct);
        s.erase(remove_first, s.end());
        return s;
    }
    int main()
    {
        std::map<std::string, size_t> word_count;
        std::string word;
        while (std::cin >> word)
            ++word_count[change_to_same(word)];
        for (auto i : word_count)
            std::cout << i.first << " " << i.second << std::endl;
    }
```


### 11.5 解释`map`和`set`的区别。你如何选择使用哪个？

**解：**
* `map`是键值对，而`set`只有关键字。当需要将关键字和数量匹配起来的时候使用前者，反之使用后者


### 11.6 解释`set`和`list`的区别。你如何选择使用哪个？

**解：**
* `set`是有序的不重复关联容器；`list`是链表，并没有规定有序和不重复


### 11.7 定义一个`map`，关键字是家庭的姓，值是一个`vector`，保存家中孩子（们）的名。编写代码，实现添加新的家庭以及向已有家庭中添加新的孩子。

**解：**
```cpp
    #include <iostream>
    #include <map>
    #include <string>
    #include <vector>

    int main()
    {
        std::map<std::string, std::vector<std::string>> names;
        std::string firstname, lastname;// 名&姓
        while (std::cin >> lastname)
            while (std::cin >> firstname)
                names[lastname].push_back(firstname);
    }
```


### 11.8 编写一个程序，在一个`vector`而不是一个`set`中保存不重复的单词。使用`set`的优点是什么？

**解：**
```cpp
    #include <iostream>
    #include <set>
    #include <string>
    #include <vector>
    #include <algorithm>

    int main()
    {
        std::vector<std::string> svec;
        std::string s;
        while (std::cin >> s)
        {
            if (find(svec.begin(), svec.end(), s) == svec.end())
                svec.push_back(s);
        }
        for (auto i : svec)
            std::cout << i << " ";
    }
```


### 11.9 定义一个`map`，将单词与一个行号的`list`关联，`list`中保存的是单词所出现的行号。

**解：**
* `std::map<std::string, std::list<sizt_t>> str_szt;`


### 11.10 可以定义一个`vector<int>::iterator`到`int`的`map`吗？`list<int>::iterator`到`int`的`map`呢？对于两种情况，如果不能，解释为什么。

**解：**
* `vector`支持关系运算符而`list`并不支持，因此前者可以定义而后者不行


### 11.11 不使用`decltype`重新定义`bookstore`。

**解：**
```cpp
    using PF = bool(*) (const Sales_data &sd1, const Sales_data &sd2)
    std::multiset<Sales_data, PF> bookstore(PF);
``` 


### 11.12 编写程序，读入`string`和`int`的序列，将每个`string`和`int`存入一个`pair`中，`pair`保存在一个`vector`中。

**解：**
```cpp
    #include <iostream>
    #include <utility>
    #include <string>
    #include <vector>
    #include <algorithm>

    int main()
    {
        std::vector<std::pair<std::string, int>> vec;
        std::string s;
        int i;
        while (std::cin >> s >> i)
        {
            vec.push_back(make_pair(s, i));
        }
        for (auto i : vec)
            std::cout << i.first << " " << i.second << std::endl;
    }
```


### 11.13 在上一题的程序中，至少有三种创建`pair`的方法。编写此程序的三个版本，分别采用不同的方法创建`pair`。解释你认为哪种形式最易于编写和理解，为什么？

**解：**
* 个人喜欢用`make_pair`，虽然比列表初始化稍长但是意义更加清晰
```cpp
    vec.push_back(make_pair(s, i));// make_pair 原版
    vec.push_back(std::pair<std::string, int> (s, i));// 括号初始化
    vec.push_back({s, i});// {}列表初始化
```


### 11.14 扩展你在11.2.1节练习中编写的孩子姓达到名的`map`，添加一个`pair`的`vector`，保存孩子的名和生日。

**解：**
```cpp
    #include <iostream>
    #include <utility>
    #include <string>
    #include <vector>
    #include <map>

    int main()
    {
        std::map<std::string, std::vector<std::pair<std::string, std::string>>> info;
        // map<string, vector<pair<string, string>>>
        std::string ln, fn, bir;
        while (std::cin >> ln >> fn >> bir)
        {
            info[ln].push_back(make_pair(fn, bir));
        }
        for (auto i : info)
        {
            std::cout << i.first << std::endl;
            for (auto ii : i.second)
                std::cout << ii.first << " " << ii.second << std::endl;
            std::cout << std::endl;
        }
        return 0;
    }
```


### 11.15 对一个`int`到`vector<int>`的`map`，其`mapped_type`、`key_type`和`value_type`分别是什么？

**解：**
* `vector<int>`
* `int`
* `pair<int, vector<int>>`


### 11.16 使用一个`map`迭代器编写一个表达式，将一个值赋予一个元素。

**解：**
```cpp
    auto map_it = map1.begin();
    map_it -> second = "helloworld";
```


### 11.17 假定`c`是一个`string`的`multiset`，`v`是一个`string`的`vector`，解释下面的调用。指出每个调用是否合法：
>```cpp
>copy(v.begin(), v.end(), inserter(c, c.end()));
>copy(v.begin(), v.end(), back_inserter(c));
>copy(c.begin(), c.end(), inserter(v, v.end()));
>copy(c.begin(), c.end(), back_inserter(v));

**解：**
* 除了第二个外都合法。原因是`multiset`没有`push_back`操作


### 11.18 写出第382页循环中`map_it`的类型，不要使用`auto`或`decltype`。

**解：**
* `std::map<std::string, sizt_t>::iterator`


### 11.19 定义一个变量，通过对11.2.2节中的名为`bookstore`的`multiset`调用`begin()`来初始化这个变量。写出变量的类型，不要使用`auto`或`decltype`。

**解：**
* `std::multiset<Sales_data, decltype(compareIsbn) *>::iterator mst_it = bookstore.begin()`


### 11.20 重写11.1节练习的单词计数程序，使用`insert`代替下标操作。你认为哪个程序更容易编写和阅读？解释原因。

**解：**
* `insert`可以准确得到结果，理解更方便；但是下标的书写更简单
```cpp
    #include <iostream>
    #include <utility>
    #include <string>
    #include <map>

    int main()
    {
        std::map<std::string, int> word_count;
        std::string s;
        while (std::cin >> s)
        {
            auto insert_it = word_count.insert(make_pair(s, 1));
            if (!insert_it.second)
                ++insert_it.first->second;
        }
    }
```


### 11.21 假定`word_count`是一个`string`到`size_t`的`map`，`word`是一个`string`，解释下面循环的作用：
>```cpp
>while (cin >> word)
>	++word_count.insert({word, 0}).first->second;

**解：**
* 如果此前没有`word`，则成功插入一个`pair`为`<word, 0>`，然后递增了计数器；如果此前已经有了`word`，则不做插入，并将其计数器+1


### 11.22 给定一个`map<string, vector<int>>`，对此容器的插入一个元素的`insert`版本，写出其参数类型和返回类型。

**解：**
* 参数类型是：`std::pair<std::string, std::vector<int>>`
* 返回类型是：`std::pair<std::map<std::string, std::vector>::iterator, bool)`


### 11.23 11.2.1节练习中的`map`以孩子的姓为关键字，保存他们的名的`vector`，用`multimap`重写此`map`。

**解：**
```cpp
    #include <iostream>
    #include <map>
    #include <string>
    #include <vector>

    int main()
    {
        std::multimap<std::string, std::vector<std::string>> names;
        std::string firstname, lastname;// 名&姓
        while (std::cin >> lastname)
            while (std::cin >> firstname)
                names.emplace(make_pair(lastname, firstname));
    }
```


### 11.24 下面的程序完成什么功能？
>```cpp
>map<int, int> m;
>m[0] = 1;

**解：**
* 初始化了一个空`map`，并添加了一个关键字为0的`pair`进去，对应的值为1


### 11.25 对比下面的程序与上一题程序
>```cpp
>vector<int> v;
>v[0] = 1;

**解：**
* 初始化创建了一个空的`vector`，并访问`v[0]`，因此此行为为未定义的


### 11.26 可以用什么类型来对一个`map`进行下标操作？下标运算符返回的类型是什么？请给出一个具体例子——即，定义一个`map`，然后写出一个可以用来对`map`进行下标操作的类型以及下标运算符将会返回的类型。

**解：**
```cpp
    std::map<std::string ,int> map1 = {{"dq", 1}, {"dongqi", 2}};
    std::map<std::string, int>::key_type// 操作类型
    std::map<std::string, int>::mapped_type// 返回类型
```


### 11.27 对于什么问题你会使用`count`来解决？什么时候你又会选择`find`呢？

**解：**
* 需要计数，通常是可重复元素的容器，且不需要向容器内插入元素时使用`count`；对不可重复元素的容器，使用`find`，但需要注意插入新元素问题


### 11.28 对一个`string`到`int`的`vector`的`map`，定义并初始化一个变量来保存在其上调用`find`所返回的结果。

**解：**
```cpp
    std::map<std::string, std::vector<int>> m1;
    std::map<std::string, std::vector<int>>:: iterator iter = m1.find("aabb");
```


### 11.29 如果给定的关键字不在容器中，`upper_bound`、`lower_bound` 和`equal_range`分别会返回什么？

**解：**
* 前两者返回相同的迭代器，指向不影响排序的迭代器位置
* `equal_range`返回一个`pair`，两个元素都为尾后迭代器


### 11.30 对于本节最后一个程序中的输出表达式，解释运算对象`pos.first->second`的含义。

**解：**
* `pos.first`是`equla_range`返回的`pair`的前一个迭代器，是找到的序列的开头；`->second`输出了它的第二个变量


### 11.31 编写程序，定义一个作者及其作品的`multimap`。使用`find`在`multimap`中查找一个元素并用`erase`删除它。确保你的程序在元素不在`map `中时也能正常运行。

**解：**
```cpp
    #include <iostream>
    #include <map>
    #include <string>
    #include <vector>

    int main()
    {
        std::multimap<std::string, std::string> m1{{"dq", "cpp"}, {"dongqi", "primer"}, {"dq", "dsaa"}, {"dongqi", "os"}};
        std::string name{"dongqi"};
        std::string book{"os"};
        auto name_pos = m1.find(name);
        auto name_num = m1.count(name);
        while (name_num != 0)
        {
            if (name_pos->second == book)
            {
                m1.erase(name_pos);
                break;
            }
            ++name_pos;
            --name_num;
        }
        return 0;
    }
```


### 11.32 使用上一题定义的`multimap`编写一个程序，按字典序打印作者列表和他们的作品。

**解：**
```cpp
    #include <map>
    #include <set>
    #include <string>
    #include <iostream>

    using std::string;

    int main()
    {
        std::multimap<string, string> authors{
            { "alan", "DMA" },
            { "pezy", "LeetCode" },
            { "alan", "CLRS" },
            { "wang", "FTP" },
            { "pezy", "CP5" },
            { "wang", "CPP-Concurrency" } };
        std::map<string, std::set<string>> order_authors;

        for (const auto &author : authors)
            order_authors[author.first].insert(author.second);

        for (const auto &author : order_authors)
        {
            std::cout << author.first << ": ";
            for (const auto &work : author.second)
                std::cout << work << " ";
            std::cout << std::endl;
        }

        return 0;
    }
```


### 11.33 实现你自己版本的单词转换程序。

**解：**
```cpp
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <map>
    #include <sstream>
    // 通过文件1建立转换关系；再在读取文件2逐个处理单词时，检测是否=map.first？ x 
    // 转换单独写一个函数：找到缩写就trans，找不到直接return
    auto make_map(std::ifstream &map_file)// 输入文件1，建立对应关系
    {// 即把一行两个单词的文件建立成为1对1的map
        std::map<std::string, std::string> trans_rule;
        std::string s, str;// s->before, ss->after
        while (map_file >> s && getline(map_file, str))// u -> you
            trans_rule[s] = str.substr(1);// str = [ you]
        return trans_rule;
    }
    auto trans_words(std::string &s, std::map<std::string, std::string> &trans_rule)
    {// 处理单个词时遍历整个map，找到匹配则替换
        auto iter = trans_rule.find(s);
        if ( iter != trans_rule.end())
            return iter->second;
        else
            return s;
    }
    auto trans_file2_according_to_file1map(std::ifstream &mapfile, std::ifstream &textfile)
    {
        auto trans_map = make_map(mapfile);
        std::string text;// 逐行读取textfile
        while (getline(textfile, text))
        {
            std::istringstream inputline(text);
            std::string word;
            while (inputline >> word)
                std::cout << trans_words(word, trans_map) << " ";
            std::cout << std::endl;
        }
    }

    int main()
    {
        std::ifstream file1("C:\/Users\/DONGQI\/Desktop\/1.txt"), file2("C:\/Users\/DONGQI\/Desktop\/2.txt");
        if (file1 && file2)
            trans_file2_according_to_file1map(file1, file2);
        else
            std::cerr << "error" << std::endl;
        return 0;
    }
```


### 11.34 如果你将`transform`函数中的`find`替换为下标运算符，会发生什么情况？

**解：**
* `find`会对句子中的任何未出现在`map`内的元素进行添加


### 11.35 在`buildMap`中，如果进行如下改写，会有什么效果？
>```cpp
>trans_map[key] = value.substr(1);
>//改为
>trans_map.insert({key, value.substr(1)});

**解：**
* `map`的`insert`操作对于关键字重复的情况下，并不会添加新元素，因此会按照第一次的`pair`储存；使用下标操作则会覆盖旧值


### 11.36 我们的程序并没检查输入文件的合法性。特别是，它假定转换规则文件中的规则都是有意义的。如果文件中的某一行包含一个关键字、一个空格，然后就结束了，会发生什么？预测程序的行为并进行验证，再与你的程序进行比较。

**解：**
* 根据`buildMap`函数中的规定，如果关键字后的对应值并不存在，则会抛出一个`runtime_error`


### 11.37 一个无序容器与其有序版本相比有何优势？有序版本有何优势？

**解：**
* 无序版本的性能更好；有序容器按照严格弱序排列，方便控制输出格式


### 11.38 用`unordered_map`重写单词计数程序和单词转换程序。

**解：**
* NULL