#include <iostream>
#include <vector>
using std::vector;

int fun(int, int);
int f_add(int i1, int i2) {
    return i1 + i2;
}
int f_sub(int i1, int i2) {
    return i1 - i2;
}
int f_pub(int i1, int i2) {
    return i1 * i2;
}
int f_div(int i1, int i2) {
    return i1 / i2;
}

int main() {
    vector<int (*)(int, int)> fv = {f_add, f_sub, f_pub, f_div};
    int i1 = 42, i2 = 2;

    for (auto &i: fv) {
        std::cout << i(i1, i2) << std::endl;
    }

    return 0;
}