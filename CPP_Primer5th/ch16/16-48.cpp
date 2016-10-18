#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::ostringstream;

template <typename T>
string debug_rep(const T &t) {
    ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T>
string debug_rep(T *p) {
    ostringstream ret;
    ret << "Pointer: " << p;
    if (ret) {
        ret << debug_rep(*p);
    } else {
        ret << "NULL";
    }
    return ret.str();
}

string debug_rep(const string &s) {
    return '"' + s + '"';
}

int main() {
    int i = 42;
    std::cout << debug_rep(&i);
}
