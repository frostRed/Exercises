#include <iostream>
#include <random>
using std::default_random_engine;
using std::uniform_int_distribution;

unsigned fun() {
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u;
    return u(e);
}

int main () {
    for (auto i = 0; i != 5; ++i) {
        std::cout << fun() << std::endl;
    }
}
