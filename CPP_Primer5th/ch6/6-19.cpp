#include <iostream>
#include <vector>
using std::vector;

double calc(double d) {
    return d;
}
int sum_fun(vector<int>::iterator iv_ite1, vector<int>::iterator iv_ite2, int i) {
    return 42;
}
int main() {
    std::cout << calc(66) << std::endl;
    vector<int> vec(10);
    std::cout << sum_fun(vec.begin(), vec.end(), 3.8) << std::endl;
    return 0;
}
