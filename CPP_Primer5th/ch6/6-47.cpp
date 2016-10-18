#include <iostream>
#include <vector>
#include <iterator>
using std::vector;
using std::iterator;

void print_vec(vector<int>::iterator beg, vector<int>::iterator end) {

    #ifndef NDEBUG
    std::cout << "vector's size is " << end - beg << std::endl;

    #endif

    if (beg != end) {
        std::cout << *beg << std::endl;
        print_vec(beg + 1, end);
    }
    else {
        std::cout << std::endl;
    }
}
int main() {
    vector<int> iv{1, 2, 3};
    print_vec(iv.begin(), iv.end());

    return 0;
}
