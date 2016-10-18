#include <iostream>

template <typename T>
auto sum(T val1, T val2) -> decltype(val1 + val2) {
    return val1 + val2;
}

int main() {
    std::cout << sum(1e42, 3e44) << std::endl;
}
