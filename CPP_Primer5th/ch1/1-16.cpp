#include <iostream>

int main() {
    int sum = 0, v = 0;

    while (std::cin >> v)
        sum += v;

    std::cout << sum << std::endl;

    return 0;
}
