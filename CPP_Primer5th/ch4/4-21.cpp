#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;

int main() {
    vector<int> vi{1, 2, 3, 4, 5};

    for (auto &i: vi) {
        i = (i % 2 ? i * 2 : i);
        cout << i << endl;
    }
 
    return 0;
}
