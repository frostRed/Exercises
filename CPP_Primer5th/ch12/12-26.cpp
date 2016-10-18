#include <memory>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::allocator;

int main() {
    int size{0};
    cout << "input the size: ";
    cin >> size;
    allocator<string> alloc;
    string *p = alloc.allocate(size);
    auto q = p;
    string word;
    while (cin >> word && q != p + size) {
        alloc.construct(q++, word);
    }

    while (q != p) {
        cout << *--q << endl;
        alloc.destroy(q);
    }
    alloc.deallocate(p, size);

}
