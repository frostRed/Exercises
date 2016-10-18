#include <string>
#include <cctype>

using std::string;

bool has_upper(const string &s) {
    for (auto &c: s) {
        if (isupper(c)){
            return true;
        }
    }
    return false;
}

void string_tolower(string &s) {
    for (auto &c: s) {
        tolower(c);
    }
}
