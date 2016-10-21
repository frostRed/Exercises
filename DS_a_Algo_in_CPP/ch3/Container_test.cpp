//
// Created by paysonl on 16-10-21.
//

#include "List.h"
#include "Vector.h"
//#include "Stack_list.h"
#include "Stack_vector.h"

#include <cassert>
//#include "Queue_list.h"
#include "Queue_circular_array.h"

int main() {
    /////// test List //////////////
    List<int> l{1, 2, 3, 4};
    auto l2(l);
    auto l3(std::move(l2));

    assert(*l.begin() == 1);

    l3 = l;
    l3 = std::move(l);
    assert(l3.back() == 4);
    assert(l3.front() == 1);


    /////// test Vector //////////////
    Vector<int> v(10);
    assert(v.sz() == 10);

    Vector<double> v2{1.5, 2, 3, 4, 5};
    assert(*(v2.begin()) == 1.5);

    auto v3(v2);
    v3 = v2;
    auto v4(std::move(v3));
    v4 = Vector<double>{4, 6, 8};

    /////////// test Stack ///////////
    Stack<int> s{1, 2, 3, 4};
    auto s2(s);
    s.push(5);
    assert(s.top() == 5);

    auto s3(std::move(s2));
    s3 = std::move(s);
    assert(s3.top() == 5);
    s3.pop();
    assert(s3.top() == 4);

    assert(s3.pop() == 4);
    assert(s3.top() == 3);


    //////////// test Queue ///////////
    Queue<int> q{1, 2, 3, 4};
    auto q2(q);
    q2 = q;
    q.enqueue(5);
    assert(q.back() == 5);
    assert(q.front() == 1);
    q.dequeue();
    auto tmp = q.front();
    //assert(q.front() == 2);

    auto q3(std::move(q2));
    q3 = std::move(q);

    //////////////////////////

}
