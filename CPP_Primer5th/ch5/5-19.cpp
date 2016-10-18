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
    string rsp;
    do {
        string s1, s2;
        cout << "Enter two strings: " << endl;
        cin >> s1 >> s2;
        cout << (s1.size() < s2.size() ? s1 : s2) << endl;
        cout << "continue enter yes: " << endl;
        cin >> rsp;
    }
    while (!rsp.empty() && rsp[0] == 'y');
 
    return 0;
}
