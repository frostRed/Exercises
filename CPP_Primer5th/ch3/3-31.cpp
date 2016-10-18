#include <iostream>
#include <cstddef>

int main() {
    int ia[10];
    for (size_t index = 0; index < 10; ++index) {
        ia[index] = index;
        std::cout << ia[index] << std::endl;
    }
    return 0;
}
