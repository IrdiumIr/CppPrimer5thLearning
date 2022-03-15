// <string_view>    {数据的起始指针，数据的长度}
// string.find()
// string.length()
// string.substr()
// string::npos

#include <iostream>
#include <vector>
#include <string>
#include <string_view>

// 源文本
auto source = R"(#pragma once
#include <cmath>
#include <type_traits>

struct Milliwatt { };
struct DecibelMilliwatt { };

namespace detail {

    template<typename T>
    struct PowerUnit { };
    template<>
    struct PowerUnit<Milliwatt> {
        using Type = Milliwatt;
    };
    template<>
    struct PowerUnit<DecibelMilliwatt> {
        using Type = DecibelMilliwatt;
    };

}

template<
    typename PowerValueUnit,
    typename = typename detail::PowerUnit<PowerValueUnit>::Type
>
double to(double value) {

    if constexpr (std::is_same_v<PowerValueUnit, Milliwatt>) {
        return std::pow(10.0, value / 10.0);
    }else {
        return std::log10(value) * 10.0;
    }
)";

// 依据指定分割符将字符串拆分到vector中
// auto split(std::string_view src, char delim_char)

void split(std::string_view src, const std::string delim, std::vector<std::string_view> &lines)
{
    // auto delim{"\n"}; 按行切割
    size_t start{src.find_first_not_of(delim)};
    size_t end{0};

    while (start != std::string_view::npos)// 非全空
    {
        end = src.find_first_of(delim, (start + 1));
        
        if (end == std::string_view::npos)
            end = src.length();

        //lines.push_back(std::string{src.substr(start, (end - start))});
        lines.push_back(src.substr(start, (end - start)));
        start = src.find_first_not_of(delim, (end + 1));
    }
}

//auto print(std::vector<std::string_view> src, size_t line)
void print(std::vector<std::string_view> lines, size_t line)
{
    std::cout << "Wanted line: " << line << '\n' << '\t' << lines[line] << std::endl;
}

int main()
{
    std::vector<std::string_view> toLines;
    split(source, "\n", toLines);

    std::string line_no{};

    // while(true)

    for (;;)
    {
        std::cout << "Plz input wanted LineNumber(Input 'q' to exit): ";
        std::cin >> line_no;
        if(line_no=="q")
        {
            break;
        }
        // else
        //     continue;
        print(toLines, std::stoi(line_no));
        std::cin.clear();
    }
    return 0;
}

//1.使用find和substr如何把空行包括进去
//2.是否能在不确定输入参数类型，且不进行参数类型转换情况下，根据输入重载？
//3.string_view是仅可读的，代替了const string&。那么对string_view是否有const/&/*？为什么？
//4.读例程无法理解emplace_back(char*, length)是如何把空行包括在内的
//5.(2)作废
//6.cpp是否有自带stl函数能够按行分割