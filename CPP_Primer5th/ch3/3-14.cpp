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

    for (auto i: iv)
        cout << i << endl;

    return 0;
}
