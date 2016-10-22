//
// Created by paysonl on 16-10-22.
//

#include "List.h"

#include <cassert>

template <typename Iterator, typename Object>
Iterator find(Iterator start, Iterator end, const Object& x) {
    for (; start != end; ++ start) {
        if (*start == x)
            return start;
    }
    return end;
};

int main() {
    List<int> l{1, 2, 3, 4};
    assert(*find(l.cbegin(), l.cend(), 3) == 3);
    assert(find(l.cbegin(), l.cend(), 7) == l.cend());

}