//Ex6.44  将6.2.2节的isShorter函数改写成内联函数。

inline bool isShorter(const string &s1, const string &s2)
{
    return (s1.size() < s2.size());
}