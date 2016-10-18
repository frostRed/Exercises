#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::istream;

vector<int> *dync() {
    auto *p = new vector<int>();
    return p;
}

vector<int> *read(istream &in, vector<int> *vi_ptr) {
    int val;
    while (in >> val) {
        vi_ptr->push_back(val);
    }
    return vi_ptr;
}

void print(vector<int> *vi_ptr) {
    for (auto i: *vi_ptr) {
        cout << i << endl;
    }
    delete vi_ptr;
}

int main() {
    auto p = dync();
    auto q = read(cin, p);
    print(q);
    p = nullptr;

    return 0;
}
