//
// Created by paysonl on 16-10-22.
//

#include "List.h"
#include "Vector.h"
#include <iostream>

template <typename Iterator, typename Object>
Iterator binarySearch(Iterator start, Iterator end, const Object& x) {
    Iterator left = start;
    Iterator right = end + 1;
    while (left <= right) {
        Iterator mid = left + (right - left) / 2;
        if (*mid == x)
            return mid;
        else if (*mid > x)
            right = mid - 1;
        else if (*mid < x)
            left = mid + 1;
    }
    return end;
};

template <typename Object>
List<Object> intersection(const List<Object>& l1, const List<Object>& l2) {
    // l1 and l2 must be sorted
    Vector<Object> v;
    for (auto &i: l1)
        v.push_back(i);

    List<int> ret;
    for (auto &i: l2)
        if (binarySearch(v.cbegin(), v.cend(), i) != v.cend())
            ret.push_back(i);
    return ret;
}

int main() {
    List<int> l1{1, 3, 5, 7};
    List<int> l2{2, 3, 5, 9};
    auto r = intersection(l1, l2);
    for (auto &i: r)
        std::cout << i << std::endl;
}
