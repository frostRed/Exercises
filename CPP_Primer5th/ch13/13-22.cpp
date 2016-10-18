#include <iostream>
using std::string;

class HasPtr {
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

    void test() {
        delete ps;
        //ps = new string("abc");
    }

//private:
    string *ps;
    int i;
};

int main() {
    HasPtr h("tring");
    h.test();
    std::cout << *h.ps << h.i << std::endl;

    
}
