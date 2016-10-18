#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item item, currItem;
    if (std::cin >> currItem) {
        int cnt = 1;
        while (std::cin >> item) {
            if (item.isbn() == currItem.isbn()) {
                ++cnt;
            }
            else {
                std::cout << currItem << " occurs " << cnt << " times" << std::endl;
                cnt = 1;
                currItem = item;
            }
        }
        std::cout << currItem << " occurs " << cnt << " times" << std::endl;

    }
}
