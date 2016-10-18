#include <vector>
#include <iostream>
#include <iterator>
#include <list>
#include <deque>

int main() {
    std::vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> il;
    std::deque<int> id;
    std::vector<int> vi2;
    auto inse_front = front_inserter(id);
    auto inse_back = back_inserter(vi2);
    auto inse = inserter(il, il.begin());

    copy(vi.begin(), vi.end(), inse_front);
    copy(vi.begin(), vi.end(), inse_back);
    copy(vi.begin(), vi.end(), inse);

    // 往前插，顺序会倒着
    for (auto i: id) {
        std::cout << i << std::endl;
    }
    // 往后插，顺序不变
    for (auto i: vi2) {
        std::cout << i << std::endl;
    }
    // 中间往前插，顺序不变
    for (auto i: il) {
        std::cout << i << std::endl;
    }
    return 0;
}
