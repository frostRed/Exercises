#include <iostream>
using std::string;

class HasPtr {
public:
    HasPtr(const string &s = string()): ps(new string(s)), i(0), use(new size_t(1)) {}

    HasPtr(const HasPtr &h);
    HasPtr &operator=(const HasPtr &h);

    ~HasPtr();


private:
    string *ps;
    int i;
    size_t *use;
};
HasPtr::HasPtr(const HasPtr &h): ps(h.ps), i(h.i), use(h.use) {
    ++*use;
}
HasPtr &HasPtr::operator=(const HasPtr &h) {
   ++*h.use; 
   if (--*use == 0) {
       delete ps;
       delete use;
   }
   ps = h.ps;
   i = h.i;
   use = h.use;
   return *this;
}
HasPtr::~HasPtr() {
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}


int main() {
    HasPtr h("tring");

    
}
