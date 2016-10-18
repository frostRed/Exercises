#include <iostream>
#include <sstream>
#include <string>
using std::cout;
using std::ostringstream;
using std::ostream;
using std::string;


/////////////////////////////////////
template <typename T>
string debug_rep(const T &t) {
    ostringstream ret;
    ret << t;
    return ret.str();
}
template <typename T>
string debug_rep(T *p) {
    ostringstream ret;
    ret << "Pointer: " << p << "==> ";
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

///////////////////////////////////
template <typename T>
ostream& print(ostream &os, const T &t) {
    return os << t << ", ";
}
template <typename T, typename... Args>
ostream& print(ostream &os, const T &t, const Args&... rest) {
    os << t << ", ";
    return print(os, rest...);
}

///////////////////////////////
template <typename... Args>
ostream& errorMsg(ostream &os, const Args&... rest) {
    return print(os, debug_rep(rest)...);
}


int main() {
    int i = 42;
    std::string s = "well";
    double d = 4.2;
    char c = 'c';
    string *ps = &s;
    int *pi = &i;
    errorMsg(cout, i, pi, s, ps, &d, d, c, "he");
}
