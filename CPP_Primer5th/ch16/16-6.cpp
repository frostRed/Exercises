#include <iostream>

template <typename T, size_t N>
T *begin(T (&arr)[N]) {
    return arr;
}

template <typename T, size_t N>
T *end(T (&arr)[N]) {
    return arr + N;
}

template <typename T, size_t N>
const T *begin(const T (&arr)[N]) {
    return arr;
}

template <typename T, size_t N>
const T *end(const T (&arr)[N]) {
    return arr + N;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    std::cout << *begin(arr) << std::endl;

}
