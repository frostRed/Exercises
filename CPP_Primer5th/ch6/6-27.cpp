#include <iostream>
#include <initializer_list>
using std::initializer_list;

int fun(initializer_list<int> il) {
    int ret = 0;
    for (const auto &elem: il) {
        ret += elem;
    }
    return ret;
}

int main() {
    int val = 4;

    std::cout << fun({1, 2, 3, val}) << std::endl;

    return 0;
}
