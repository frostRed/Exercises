#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

void f1();
void f2();

int main() {
    f1();
    f2();

    return 0;
}
void f1() {
    string s;
    while (getline(cin, s)) {
        cout << s << endl;
    }
}

void f2() {
    string s;
    while (cin >> s) {
        cout << s << endl;
    }
}
