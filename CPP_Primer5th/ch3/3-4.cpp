#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void f1() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 >= s2) {
        cout << s1 << endl;
    }
    else {
        cout << s2 << endl;
    }
}
void f2() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.size() >= s2.size()) {
        cout << s1 << endl;
    }
    else {
        cout << s2 << endl;
    }
}
int main() {
    f1();
    f2();

    return 0;
}
