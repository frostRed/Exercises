#include <iostream>
#include <list>
#include <string>

using std::list;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    list<string> str_l;
    string word;
    while (cin >> word) {
        str_l.push_back(word);
    }
    for (auto beg = str_l.cbegin(); beg != str_l.cend(); ++beg) {
        cout << *beg << endl;
    }

    return 0;
}
