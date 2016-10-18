#include <iostream>
#include <vector>
#include <cstddef>
using std::vector;

int main() {
    const unsigned arr_size = 10;
    int ia[arr_size];
    for (size_t index = 0; index < arr_size; ++index) {
        ia[index] = index;
        std::cout << ia[index] << std::endl;
    }

    int ia_cpy[arr_size];
    for (size_t index = 0; index < arr_size; ++index) {
        ia_cpy[index] = ia[index];
        std::cout << ia_cpy[index] << std::endl;
    }

    vector<unsigned> iv;
    for (unsigned i = 0; i < arr_size; i++)
        iv.push_back(i);

    vector<unsigned> iv_cpy = iv;


    return 0;
}
