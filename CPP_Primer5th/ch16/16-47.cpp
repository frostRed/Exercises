#include <iostream>
#include <utility>

template <typename F, typename T1, typename T2>
void flip(F f, T1 &&v1, T2 &&v2) {
    f(std::forward<T2>(v2), std::forward<T1>(v2));
}

void f(int v1, int &v2) {
    ++v2;
}

void g(int &&v1, int &v2) {
    ++v1;
}


