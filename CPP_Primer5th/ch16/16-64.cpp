#include <iostream>
#include <vector>
#include <string>
#include <cstring>

template <typename I, typename V>
size_t cnt(const I &beg, const I &end, V v) {
    std::cout << "normal" << std::endl;
    size_t n = 0;
    for (size_t i = 0; beg + i != end; ) {
        if (*(beg + i) == v)
            ++n;
        ++i;
    }
    return n;
}

template<>
size_t cnt(const std::vector<const char *>::const_iterator &c1, const std::vector<const char *>::const_iterator &c2, const char *c) {
    std::cout << "spe" << std::endl;
    size_t n = 0;
    for (size_t i = 0; (c1 + i) != c2; ) {
        if (strcmp(*(c1 + i), c) == 0)
            ++n;
        ++i;
    }
    return n;
}

int main() {
    std::vector<const char*> cv{"ab", "cd", "ab", "ab"};

    std::cout << cnt(cv.cbegin(), cv.cend(), "ab") << std::endl;
}
