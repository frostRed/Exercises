#include <iostream>
#include <string>

template <typename T, size_t N>
void print(const T (&arr)[N]) {
    for (size_t i = 0; i != N; ++i)
        std::cout << *(arr + i) << std::endl;
}

int main() {
    int iarr[5] = {1, 2, 3, 4};
    std::string sarr[3] = {"abc", "efg", "xyz"};
    print(iarr);
    print(sarr);
}
