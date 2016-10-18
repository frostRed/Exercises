#include <iostream>
int main() {
    int val = 4;
    auto f = [val](int i1) {return val + i1;};
    std::cout << f(1) << std::endl;

    return 0;
}
