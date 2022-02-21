// 第一阶段测试示范程序

#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <cctype>
#include <cstdlib>

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
auto split(std::string_view src, char delim_char){
    std::vector<std::string_view> res;

    auto idx_from_right = -1;

    for(auto i = 0; i < static_cast<int>(src.size()); ++i){
        if(src[i] == delim_char){
            auto idx_from_left = idx_from_right;
            idx_from_right = i;
            const auto idx = idx_from_left + 1;
            res.emplace_back(src.data() + idx, idx_from_right - idx);
        }
    }

    res.emplace_back(src.data() + idx_from_right + 1, src.size() - idx_from_right - 1);
    return res;

}

auto print(std::vector<std::string_view> src, size_t line){
    std::cout << "line: " << line << " -> " << src[line] << '\n';
}

// 检查字符串中是否全部为数字
auto check(std::string const& str){
    for(const auto& c: str){
        if(!std::isdigit(c)){
            std::cout << "Please input a number greater than 0.\n";
            return false;
        }
    }
    return true;
}

int main(){
    auto views = split(source, '\n');
    std::string line_no{};
    while(true){
        std::cout << "Input line no.(input 'q' to exit): ";
        std::getline(std::cin, line_no);
        if(line_no == "q"){
            break;
        }
        if(!check(line_no)){
            continue;
        }
        print(views, std::stoi(line_no));
        std::cin.clear();
    }
    return 0;
}