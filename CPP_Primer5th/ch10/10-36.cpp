#include <iostream>
#include <list>
#include <algorithm>

int main() {
    std::list<int> li{1, 2, 3, 0, 4};
    auto ite = find(li.crbegin(), li.crend(), 0);
    std::cout << *ite << std::endl;
    return 0;
}
