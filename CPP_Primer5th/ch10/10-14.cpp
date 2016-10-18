#include <iostream>
int main() {
    auto f = [](int i1, int i2) {return i1 + i2;};
    std::cout << f(1, 2) << std::endl;
    return 0;
}
