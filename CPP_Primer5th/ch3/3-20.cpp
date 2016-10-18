#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    vector<int> iv;
    int i = 0;
    while (cin >> i)
        iv.push_back(i);

    auto iv_size = iv.size();
    for (decltype(iv_size) index = 0; index + 1 < iv_size; index+=2) {
        cout << iv[index] + iv[index + 1] << endl;
    }

    cout << endl;
    decltype(iv_size) index = 0;
    while (index < iv_size/2) {
        cout << iv[index] + iv[iv_size - 1 - index] << endl;;
        ++index;
    }

    return 0;
}
