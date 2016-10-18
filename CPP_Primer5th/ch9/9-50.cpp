#include <string>
#include <vector>
#include <iostream>

int main() {
    std::vector<std::string> dstr = {"3.14", "6.28"};
    double resu = 0;
    for (auto &i: dstr) {
        resu += stod(i);
    }
    std::cout << resu << std::endl;
    return 0;
}
