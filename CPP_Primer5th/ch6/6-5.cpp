#include <iostream>

unsigned f_abs(int val) {
    if (val >= 0)
        return val;
    else
        return -val;
}

int main () {
    int val;
    std::cout << "Enter a number: ";
    std::cin >> val;
    std::cout << val <<"'s abs is " << f_abs(val) << std::endl;

    return 0;
}
