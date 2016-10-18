#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    vector<string> text{"hello", "world", "    "};
    for (auto it = text.begin();
            it != text.end() && !it->empty(); ++it) {
        for (auto str_ite = it->begin(); str_ite != it->end(); ++str_ite) {
            (*str_ite) = toupper(*str_ite);
            cout << *str_ite;
        }

    }
 
    return 0;
}
