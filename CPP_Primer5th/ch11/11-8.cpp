#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::vector;


int main() {
    vector<int> ivec{1, 3, 3, 2, 2, 5, 5, 4, 4, 3, 9, 9};
    sort(ivec.begin(), ivec.end());
    vector<int> iset;
    unique_copy(ivec.begin(), ivec.end(), back_inserter(iset));


    for (auto i: iset) {
        std::cout << i << std::endl;
    }
}
