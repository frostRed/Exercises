#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cstddef>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;
using std::size_t;

int main() {
    int ia[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    for (int (&i_arr)[4] : ia)
        for (int  i: i_arr)
            cout << i << endl;
    for (size_t i = 0; i < 3; ++i)
        for (size_t ii = 0; ii < 4; ++ii)
            cout << ia[i][ii] << endl;

    for (int (*p)[4] = ia; p != ia + 3; ++p)
        for (int *i = *p; i != *p + 4; ++ i)
            cout << *i << endl;

    return 0;
}
