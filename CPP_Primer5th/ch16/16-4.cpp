#include <iostream>
#include <list>
#include <vector>
#include <string>

template <typename I, typename V>
I &find(I &&beg, I &&end, V val) {
    while (beg != end) {
        if (*beg == val) return beg;
        ++beg;
    }
    return end;
}
template <typename I, typename V>
I &find(I &beg, I &end, V val) {
    while (beg != end) {
        if (*beg == val) return beg;
        ++beg;
    }
    return end;
}

int main() {
    std::vector<int> vi{1, 2, 3, 4};
    std::list<std::string> ls{"abc", "efg", "xyz"};

    std::cout << *find(vi.begin(), vi.end(), 4) << std::endl;
    std::cout << *find(ls.begin(), ls.end(), "efg") << std::endl;

}
