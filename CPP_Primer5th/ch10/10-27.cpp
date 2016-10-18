#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>

int main() {
    std::vector<int> vi{1, 1, 2, 2, 2, 3};
    std::list<int> il;
    auto inserter = back_inserter(il);
    unique_copy(vi.begin(), vi.end(), inserter);
    for (auto i: il) {
        std::cout << i << std::endl;
    }
    return 0;
}
