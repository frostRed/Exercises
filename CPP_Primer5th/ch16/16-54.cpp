#include <iostream>
#include <string>
using std::cout;
using std::ostream;


template <typename T>
ostream& print(ostream &os, const T &t);

template <typename T, typename... Args>
ostream& print(ostream &os, const T &t, const Args&... rest) {
    os << t << ", ";
    return print(os, rest...);
}

class NoOut {
private:
    int val = 0;
};
int main() {

    int i = 42;
    std::string s = "well";
    double d = 4.2;
    char c = 'c';
    NoOut no;
    print(cout, i, s, d, c, no, "he");
}

template <typename T>
ostream& print(ostream &os, const T &t) {
    return os << t;
}
