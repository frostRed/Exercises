#include <vector>
#include <iostream>

using std::cout;
using std::endl;
int main() {
    std::vector<int> v(10, 2);
    cout << v.size() << " " << v.capacity() << endl;
    v.resize(20);
    v.push_back(1);
    cout << v.size() << " " << v.capacity() << endl;
    v.resize(5);
    cout << v.size() << " " << v.capacity() << endl;
}
