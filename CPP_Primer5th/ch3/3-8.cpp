#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string s;
    cin >> s;

    for (decltype(s.size()) i = 0; i != s.size(); ++i)
        s[i] = 'Y';

    decltype(s.size()) i = 0;
    while (i != s.size()) {
        s[i] = 'Z';
        i++;
    }

    for (char &c: s)
        c = 'X';

    cout << s << endl;
    return 0;
}
