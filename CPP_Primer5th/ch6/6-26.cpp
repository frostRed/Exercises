#include <iostream>

int main(int argc, char *argv[]) {
    std::cout << "argc = " << argc << std::endl;
    while (*argv) {
        std::cout << *argv++ << std::endl;
    }
    return 0;
}
