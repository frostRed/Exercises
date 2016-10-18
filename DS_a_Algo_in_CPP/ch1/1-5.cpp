//
// Created by paysonl on 16-10-18.
//

#include <string>
#include <cassert>

int run(int);

int main(int argc, char** argv) {
    int num = std::stoi(argv[1]);
    int count = run(num);
    assert(count == 3);
    return 0;
}

int run(int n) {
    if (n == 0)
        return 0;
    else if (n % 2 == 0)
        return run(n  / 2);
    else if (n % 2 == 1)
        return 1 + run(n / 2);
}
