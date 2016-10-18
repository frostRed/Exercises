#include <iostream>
#include <deque>
#include <string>

using std::deque;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    deque<string> str_dq;
    string word;
    while (cin >> word) {
        str_dq.push_back(word);
    }
    for (auto beg = str_dq.cbegin(); beg != str_dq.cend(); ++beg) {
        cout << *beg << endl;
    }

    return 0;
}
