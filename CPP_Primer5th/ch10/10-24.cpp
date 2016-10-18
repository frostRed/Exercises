#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std::placeholders;
using std::string;

bool check_size(int i, string::size_type sz) {
    return i > sz;
}
int main() {
    string s{"abcdef"};
    std::vector<int> iv{1, 2, 3, 5, 8, 10, 7};
    auto i = find_if(iv.cbegin(), iv.cend(), bind(check_size, _1, s.size()));
    if (i == iv.end()) {
        std::cout << "no" << std::endl;
    } else {
        std::cout << *i << std::endl;
    }
    return 0;
}
