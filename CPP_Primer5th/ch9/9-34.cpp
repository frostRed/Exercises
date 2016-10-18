#include <vector>
#include <iostream>

int main() {
    std::vector<int> vi{2, 2, 3};
    auto iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2)
            iter = vi.insert(iter, *iter);
        ++iter;
    }

    for (auto i: vi)
        std::cout << i << std::endl;
    return 0;
}
