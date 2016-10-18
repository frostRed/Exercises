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

    for (auto b = iv.cbegin(); (b+1) != iv.cend() && (b+2) != iv.cend(); b+=2) {
        cout << *b + *(b + 1) << endl;
    }

    cout << endl;
    for (auto b = iv.cbegin(), e = iv.cend(); b != e && (b+1) != e; ++b, --e) {
        cout << *b + *(e - 1) << endl;;
    }

    return 0;
}
