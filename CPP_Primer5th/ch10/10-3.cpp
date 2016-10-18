#include <numeric>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> iv{1, 2, 3, 4, 5};
    std::cout << accumulate(iv.cbegin(), iv.cend(), 0) << std::endl;
    return 0;
}
