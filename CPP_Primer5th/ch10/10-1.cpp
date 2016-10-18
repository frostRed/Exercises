#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> iv{1, 2, 3, 4, 4, 5};
    std::cout << count(iv.begin(), iv.end(), 4) << std::endl;
    return 0;
}
