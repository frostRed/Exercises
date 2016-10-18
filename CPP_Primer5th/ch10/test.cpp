#include <iostream>

int main() {
    int v1 = 42;
    auto f= [v1]() {return ++v1;};
    v1 = 0;
    auto j = f();
    std::cout << v1 << std::endl;
    return 0;
}
