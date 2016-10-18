#include <vector>
#include <string>


std::string fun(std::vector<char> &chv) {
    std::string s;
    for (auto i: chv)
        s.push_back(i);
    return s;
}
