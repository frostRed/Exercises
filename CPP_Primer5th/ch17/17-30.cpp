#include <iostream>
#include <ctime>
using std::time;
#include <random>
using std::default_random_engine;
using std::uniform_int_distribution;

unsigned fun(int seed, unsigned min, unsigned max) {
    static default_random_engine e(seed);
    static uniform_int_distribution<unsigned> u(min, max);
    return u(e);
}

int main () {
    for (auto i = 0; i != 5; ++i) {
        std::cout << fun(time(0), 0, 500) << std::endl;
    }
}
