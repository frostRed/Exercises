#include <iostream>
#include <deque>
#include <list>
#include <string>

using std::list;
using std::deque;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    list<int> i_l{1, 2, 3, 4, 5, 6};
    deque<int> odd;
    deque<int> even;
    for (auto beg = i_l.cbegin(); beg != i_l.cend(); ++beg) {
        if (*beg % 2) {
            odd.push_back(*beg);
        } else {
            even.push_back(*beg);
        }
    }

    return 0;
}
