#include <vector>
#include <iostream>

int main() {
    std::vector<int> vi{1, 2, 3};
    for (auto i = vi.cend() - 1; i >= vi.cbegin(); --i) {
        std::cout << *i << std::endl;
    }
    return 0;
}
