#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

int main() {
    std::vector<int> vi{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> li;
    copy(vi.crbegin() + 3, vi.crbegin() + 8, back_inserter(li));

    for (auto i: li) {
        std::cout << i << std::endl;
    }
    return 0;
}
