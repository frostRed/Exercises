#include <iostream>

void fun(int i) {
    std::cout << i << std::endl;
}

int main() {
    int i = 10;
    static int j = 20;
    fun(i);

    return 0;
}
