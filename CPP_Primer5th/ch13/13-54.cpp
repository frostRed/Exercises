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
    HasPtr(HasPtr &&) noexcept;

    HasPtr &operator=(HasPtr);
    HasPtr &operator=(HasPtr &&) noexcept;

    bool operator<(const HasPtr &) const;

    ~HasPtr() {delete ps;}

    void print(std::ostream &os) const  {os << *ps << " " << i << std::endl;}

private:
    string *ps;
    int i;
};

HasPtr::HasPtr(HasPtr &&h) noexcept: ps(h.ps), i(h.i) {
    h.ps = nullptr;
}
HasPtr &HasPtr::operator=(HasPtr rhs) {
    swap(*this, rhs);
    return *this;
}
HasPtr &HasPtr::operator=(HasPtr &&rhs) noexcept {
    if (this != &rhs) {
        delete ps;
        ps = rhs.ps;
        i = rhs.i;
        rhs.ps = nullptr;
    }
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
