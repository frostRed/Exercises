#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main() {
    vector<int> iv1{1, 2, 3};
    vector<int> iv;
    cout << iv.at(0) << endl;
    cout << iv[0] << endl;
    cout << iv.front() << endl;
    cout << *iv.begin() << endl;
    return 0;
}
