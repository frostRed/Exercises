//
// Created by paysonl on 16-10-18.
//
#include <iostream>

#include "1-16.h"
#include <vector>
using std::vector;

#include <cassert>
int main() {
    Matrix<int> m(vector<vector<int>>{{1, 2, 3},
                                     {4, 5, 6}}
    );
    //assert(m.resize(2,2) == vector{vector{1, 2}, vector{3, 4}});
    assert(m.numrows() == 2);
    assert(m.numcols() == 3);
    m.resize(2, 2);
    assert(m.numrows() == 2);
    assert(m.numcols() == 2);
    return 0;
}

