#include <iostream>
#include <iterator>
using std::cout;
using std::endl;
using std::begin;
using std::end;

void print(const int *beg, const int *end) {
    while (beg != end) {
        cout << *beg++ << endl;
    }
}
void print(const int *pi, size_t size) {
    for (size_t i = 0; i != size; ++i) {
        cout << pi[i]  << endl;
    }
}

int main() {
    int i = 0, j[2] = {0, 1};
    print(&i, 1);

    print(begin(j), end(j));
    print(j, 2);

    return 0;
}
