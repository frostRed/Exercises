#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::ostringstream;

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

template <>
string debug_rep(const char *cp) {
    return string(cp);
}
template <>
string debug_rep(char *p) {
    return string(p);
}


int main() {
    
    std::cout << debug_rep("abc");
}
