#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void f1() {
    string s, total;
    while (cin >> s) {
        total += s;
    }
    cout << total << endl;
}
void f2() {
    string s, total;
    while (cin >> s) {
        total =  total + " " + s;
    }
    cout << total << endl;
}
int main() {
    f1();
    f2();
    return 0;
}
