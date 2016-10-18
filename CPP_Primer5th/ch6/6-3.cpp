#include <iostream>

int fact(int val) {
    if (val == 1)
        return 1;
    else
        return val * fact(val - 1);
}

int main () {
    std::cout << fact(5) << std::endl;

    return 0;
}
