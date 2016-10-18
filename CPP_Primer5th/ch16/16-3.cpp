#include <string>
#include <iostream>
#include "Sales_data.h"

template <typename T>
int compare(const T &v1, const T &v2) {
    if (v1 < v2) return 1;
    if (v2 > v1) return -1;
}

int main() {
    std::cout << compare(1, 2) << std::endl;
    Sales_data sd1("abc", 4, 2.0);
    Sales_data sd2("abc", 5, 3.0);
    std::cout << compare(sd1, sd2) << std::endl;
}
