#include<vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> iv{1, 2, 3, 4};
    fill_n(iv.begin(), iv.size(), 0);

    for (auto i: iv) {
        std::cout << i << std::endl;
    }
    return 0;
}
