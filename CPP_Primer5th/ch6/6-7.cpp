#include <iostream>

int fun() {
    static int ret = 0;
    return ++ret;
}

int main() {
    for (int i = 0; i < 10; ++i)
        std::cout << fun() << std::endl;

    return 0;
}
