#include <iostream>

template <typename T, size_t N>
constexpr size_t arr_size(const T (&arr)[N]) {
    return N;
}

int main() {
    int arr[5];
    std::cout << arr_size(arr) << std::endl;
}
