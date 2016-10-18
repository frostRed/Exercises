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
    int i[] = {1, 2, 3, 4};
    vector<int> vi(begin(i), end(i));
    for (auto index: vi)
        cout << index << endl;
 
    return 0;
}
