#include <iostream>

int main() {
    int v1, v2 = 0;

    std::cout << "Enter two numbers: " << std::endl;
    std::cin >> v1 >> v2;

    if (v1 > v2) {
        int tmp = v2;
        v2 = v1;
        v1 = tmp;
    }
    while (v1 <= v2) {
        std::cout << v1 << std::endl;
        ++v1;
    }

    return 0;
}
