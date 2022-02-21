#include <iostream>

int main()
{
    int sum = 0;
    for (int val = 50; val <= 100; val++) {
        sum += val;
    }
    std::cout << "Sum of 50 to 100 is " << sum << std::endl;
}  //1.9  

{
    for (int val = 10; val >=0; val--){
        std::cout << val << " ";
    }
    std::cout << std::endl;
}  //1.10

{
    int start = 0, end = 0;
    std::cout << "Input number A and B: ";
    std::cin >> start >> end;
    
    if (start > end) {
        std::cout << "ERROR : Number A should be smaller than B!";
    }
    else {
        for (; start <= end; start++) {
            std::cout << start << " ";
        }
        std::cout << std::endl;
    }
}  //1.11