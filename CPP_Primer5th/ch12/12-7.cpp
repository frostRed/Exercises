#include <iostream>
#include <vector>
#include <memory>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::make_shared;

using vi_shared = std::shared_ptr<vector<int>>;
vi_shared dync() {
    vi_shared p = make_shared<vector<int>>();
    return p;
}

vi_shared read(istream &in, vi_shared vi_ptr) {
    int val;
    while (in >> val) {
        vi_ptr->push_back(val);
    }
    return vi_ptr;
}

void print(vi_shared vi_ptr) {
    for (auto i: *vi_ptr) {
        cout << i << endl;
    }
}

int main() {
    auto p = dync();
    p = read(cin, p);
    print(p);

    return 0;
}
