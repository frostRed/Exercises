#include <array>
#include <vector>
#include <iostream>
using std::array;
using std::vector;

int main() {
    array<int, 2> ia1 = {1, 2};
    array<int, 2> ia2 = {3, 4};
    auto ite1 = ia1.begin();
    swap(ia1, ia2);
    std::cout << *ite1 << std::endl;


    vector<int> iv1{1, 2};
    vector<int> iv2{3, 4};
    auto ite2 = iv1.begin();
    swap(iv1, iv2);
    std::cout << *ite2 << std::endl;

    return 0;
}
