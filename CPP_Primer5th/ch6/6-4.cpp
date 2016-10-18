#include <iostream>

int fact(int val) {
    if (val == 1)
        return 1;
    else
        return val * fact(val - 1);
}

int main () {
    int val;
    std::cout << "Enter a number: ";
    std::cin >> val;
    std::cout << val <<"! is " << fact(val) << std::endl;

    return 0;
}
