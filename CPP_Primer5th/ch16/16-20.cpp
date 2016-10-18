#include <iostream>
#include <vector>
#include <list>

template <typename C>
void print(const C &container) {
    for (auto beg = container.begin(); beg != container.end(); ++beg) {
        std::cout << *beg << std::endl;
    }

}

int main() {
    std::vector<int> vi{1, 2, 3};
    print(vi);
}
