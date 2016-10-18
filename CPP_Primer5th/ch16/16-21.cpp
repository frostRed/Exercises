#include <iostream>
class DebugDelete {
public:
    DebugDelete(std::ostream &s = std::cerr): os(s) {};

    /*
    template <typename T>
        void operator()(const T *p) const {
            os << "const object deleted" << std::endl;
            delete p;
        }
    */
    template <typename T>
        void operator()(T *p) {
            os << "object deleted" << std::endl;
            delete p;
        }

private:
    std::ostream &os;
};

int main() {
    int * const p = new int(42);
    DebugDelete dd1(std::cout);
    dd1(p);

    const int * p2 = new int(42);
    DebugDelete dd2(std::cout);
    dd2(p2);
}
