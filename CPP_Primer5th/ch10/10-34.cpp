#include <vector>
#include <iostream>

int main() {
    std::vector<int> vi{1, 2, 3};
    for (auto i = vi.crbegin(); i != vi.crend(); ++i) {
        std::cout << *i << std::endl;
    }
    return 0;
}
