#include <iostream>

int main() {
    int i;
    while (std::cin >> i && i != 42)
        continue;
    return 0;
}
