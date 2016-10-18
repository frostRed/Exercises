#include <iostream>
#include <vector>
#include <list>

template <typename C>
void print(const C &container) {
    typename C::size_type  sz = container.size();
    for (decltype(sz) i = 0; i != sz; ++i) {
        std::cout << *(container.begin() + i) << std::endl;
    }

}

int main() {
    std::vector<int> vi{1, 2, 3};
    print(vi);
}
