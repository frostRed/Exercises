#include <iostream>
using std::string;

class HasPtr {
    friend inline void swap(HasPtr &, HasPtr &);
public:
    HasPtr(const string &s = string()): ps(new std::string(s)), i(0) {}

    HasPtr(const HasPtr &h): ps(new string(*h.ps)), i(h.i) {}
    HasPtr &operator=(const HasPtr &h) {
        auto newps = new string(*h.ps);
        delete ps;
        ps = newps;
        i = h.i;
        return *this;
    }
    ~HasPtr() {delete ps;}


private:
    string *ps;
    int i;
};

void swap(HasPtr &h1, HasPtr &h2) {
    swap(h1.ps, h2.ps);
    std::swap(h1.i, h2.i);
    std::cout << "swap()" << std::endl;
}
