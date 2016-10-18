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
    vector<int> ivec{1, 2, 3, 4};

    vector<int>::size_type cnt = ivec.size();
    for (vector<int>::size_type ix = 0;
            ix != ivec.size(); ix++, cnt--)
        ivec[ix] = cnt;

    for (auto i: ivec)
        cout << i << endl;

    return 0;
}
