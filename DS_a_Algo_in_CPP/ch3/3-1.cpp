//
// Created by paysonl on 16-10-22.
//


#include "List.h"
#include <iostream>
using std::cout;
using std::endl;

#include "lib.h"
using lib::time_count_int;


#include <vector>
using std::vector;

void fun(const List<int>&, const List<int>&);

int main() {
    List<int> p{1, 3, 4, 6};
    List<int> l{0, 1, 2, 3, 4, 5, 6, 7};
    fun(p, l);

}

void fun(const List<int>& pos, const List<int>& list) {
    // pos and list must sorted in ascending
    auto posBeg = pos.begin();
    int i = 0;
    for (auto beg = list.begin(); beg != list.end(); ++beg, ++i) {
        if (i == *posBeg) {
            cout << * beg << endl;
            ++posBeg;
        }
    }
}
