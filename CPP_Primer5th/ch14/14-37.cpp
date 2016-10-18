#include <algorithm>
#include <iostream>
#include <vector>

class Equal {
public:
    template <typename T>
    bool operator()(T &, T &) const;
};

template <typename T>
bool Equal::operator()(T &t1, T & t2) const {
    return t1 == t2;
}

int main() {
    std::vector<int> vi{1, 2, 3, 4, 5};
    std::vector<int> vi2{2, 3};
    auto ite = std::find_first_of(vi2.begin(), vi2.end(), vi.begin(), vi.end(), Equal());
    for (decltype(vi2.size()) i = 0; vi2.begin() + i != vi2.end(); ++i) {
        std::cout << *(ite + i) << std::endl;
    }

}
