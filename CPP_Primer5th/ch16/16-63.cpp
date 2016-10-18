#include <iostream>
#include <vector>
#include <string>

template <typename I, typename V>
size_t cnt(const I &beg, const I &end, V v) {
    size_t n = 0;
    for (size_t i = 0; beg + i != end; ) {
        if (*(beg + i) == v)
            ++n;
        ++i;
    }
    return n;
}

int main() {
    std::vector<double> dv{1.1, 2.2, 1.1, 3.3};
    std::vector<std::string> sv{"ab", "cd", "ab", "ab"};
    std::cout << cnt(dv.cbegin(), dv.cend(), 1.1);
    std::cout << cnt(sv.cbegin(), sv.cend(), "ab");
}
