#include <vector>
#include <algorithm>
using std::vector;

class Foo {
public:
    Foo() = default;
    Foo(const vector<int> &v): vi(v) {}

    Foo(const Foo &f): vi(f.vi) {}
    Foo(Foo &&f): vi(std::move(vi)) {}
    ~Foo() {}
    Foo &operator=(const Foo &f) { vi = f.vi; return *this;}
    Foo &operator=(Foo &&f) {vi = std::move(f.vi); return *this;}

    Foo retVal() {
        return std::move(*this);
    }
    Foo RetFoo() {
        return *this;
    }

    Foo sorted() && {
        sort(vi.begin(), vi.end());
        return *this;
    }
    /*
    Foo sorted() const & {
        Foo ret(*this);
        return ret.sorted();
    }
    */
    Foo sorted() const & {
        return Foo(*this).sorted();
    }

private:
    vector<int> vi;
};

int main() {
    Foo f = vector<int>{1, 2};
    f.sorted();
}
