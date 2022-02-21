#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item sum_item;
    for (Sales_item item; std::cin >> item; ) {
        sum_item += item;
    }
    std::cout << "Sum of sale_items is " << sum_item << std::endl;
	return 0;
}
