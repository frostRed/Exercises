#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
using std::placeholders::_1;

int main() {
    std::vector<int> v{1, 2, 4, 1036, 10000};
    auto n = count_if(v.cbegin(), v.cend(), std::bind(std::greater<int>(), _1, 1024));

    std::vector<std::string> vs{"sfjoe", "fjoe"};
    auto ite = find_if(vs.begin(), vs.end(), std::bind(std::not_equal_to<std::string>(), _1, std::string("pooh")));

    for_each(v.begin(), v.end(), std::bind(std::multiplies<int>(), _1, 2));
    
}
