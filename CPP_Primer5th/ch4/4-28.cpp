#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;

int main() {
    bool b = true;
    char c = 'c';
    short sh = 42;
    int i = 42;
    long l= 42;
    long long ll = 42;
    float f = 42.0;
    double d = 42.0;
    long double ld = 42.0;

    cout << "bool " << sizeof b << endl;
    cout << "char " << sizeof c << endl;
    cout << "short " << sizeof sh << endl;
    cout << "int " << sizeof i << endl;
    cout << "long " << sizeof l << endl;
    cout << "long long " << sizeof ll << endl;
    cout << "float " << sizeof f << endl;
    cout << "double " << sizeof d << endl;
    cout << "long double " << sizeof ld << endl;

 
    return 0;
}
