#include <iostream>

int main()
{
    int start = 0, end = 0;
    std::cout << "Input number A and B: ";
    std::cin >> start >> end;

    if (start > end) {
        std::cout << "ERROR : Number A should be smaller than B!";
    }
    else {
        while (start <= end){
            std::cout << start << " ";
            start++;
        }
        std::cout << std::endl;
    }
}  