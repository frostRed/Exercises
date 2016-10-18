#include <iostream>
#include <string>

using std::istream;
using std::cout;
using std::string;

istream &fun(istream &is) {
    string s;

    while (is >> s) {
        cout << s;
    }

    //cout << is.rdstate();

    auto tmp = is.rdstate() & ~is.eofbit;
    //cout << tmp;

    is.setstate(tmp);
    //cout << is.rdstate();
    return is;
}
