#include <iostream>
#include <vector>
#include <algorithm>
using std::string;

class HasPtr {
    friend inline void swap(HasPtr &, HasPtr &);
public:
    HasPtr(const string &s = string()): ps(new std::string(s)), i(0) {}
    HasPtr(const string &s, int val): ps(new std::string(s)), i(val) {}
    HasPtr(const HasPtr &h): ps(new string(*h.ps)), i(h.i) {}

    HasPtr &operator=(const HasPtr &);
    bool operator<(const HasPtr &) const;

    ~HasPtr() {delete ps;}

    void print(std::ostream &os) const  {os << *ps << " " << i << std::endl;}

private:
    string *ps;
    int i;
};
HasPtr &HasPtr::operator=(const HasPtr &h) {
    auto newps = new string(*h.ps);
    delete ps;
    ps = newps;
    i = h.i;
    return *this;
}
bool HasPtr::operator<(const HasPtr &h) const {
    return this->i < h.i;
}

void swap(HasPtr &h1, HasPtr &h2) {
    std::cout << "swap()" << std::endl;
    swap(h1.ps, h2.ps);
    std::swap(h1.i, h2.i);
}

int main() {
    std::vector<HasPtr> v{ {"hi", 10},
                           {"wo", 5},
                           {"fjeo", 1} };
    sort(v.begin(), v.end());
   (*v.begin()).print(std::cout);

}
