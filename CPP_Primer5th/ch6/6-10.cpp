#include <iostream>

void fun(int *i, int *j) {
    int tmp = *i;
    *i = *j;
    *j = tmp;
}

int main() {
    int i = 0, j = 42;
    fun(&i, &j);
    std::cout << i  << '\t' << j << std::endl;

    return 0;
}
