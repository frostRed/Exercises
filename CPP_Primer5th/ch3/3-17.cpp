#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    vector<string> sv;
    string s;
    while (cin >> s)
        sv.push_back(s);

    for (auto i: sv) {
        for (auto &index: i)
            index = toupper(index);
        cout << i << endl;
    }

    return 0;
}
