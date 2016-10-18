#include <iostream>
#include <vector>
using std::cout;
using std::endl;

struct X {
    X() {cout << "X()" << endl;}
    X(int) {cout << "X(int)" << endl;}
    X(const X &x) {cout << "X(const X&)" << endl;}
    X &operator=(const X&) {cout << "operator=" << endl;}
    ~X() {cout << "~X()" << endl;}
};

void fun1(X x){}
void fun2(X &x){}

int main() {
    X x1;
    X x2 = x1;
    X x3(1);
    X x4(x3);

    cout << "------------" << endl;
    fun1(x1);
    fun2(x2);

    cout << "------------" << endl;
    X *p1 = new X();
    X *p2 = new X(x1);


    cout << "------------" << endl;
    std::vector<X> v1;
    v1.push_back(x1);

    cout << "------------" << endl;
}
