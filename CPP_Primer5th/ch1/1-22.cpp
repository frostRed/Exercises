#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item item, sum;
    while (std::cin >> sum) {
        while (std::cin >> item) {
            sum += item;
        }
        break;
    }

    std::cout << sum << std::endl;

    return 0;
}
