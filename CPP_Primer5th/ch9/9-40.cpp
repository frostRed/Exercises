#include <string>
#include <vector>
#include <iostream>

int main() {
    std::vector<std::string> svec;
    svec.reserve(1024);
    int s = 1048;
    for (int i = 0; i != s; ++i) {
        svec.push_back("hello");
    }
    svec.resize(svec.size() + svec.size() / 2);
    std::cout << svec.capacity() << std::endl;;
    return 0;
}
