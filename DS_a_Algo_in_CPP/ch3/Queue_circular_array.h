//
// Created by paysonl on 16-10-21.
//

#ifndef DS_A_ALGO_IN_CPP_QUEUE_CIRCULAR_ARRAY_H
#define DS_A_ALGO_IN_CPP_QUEUE_CIRCULAR_ARRAY_H

#include <algorithm>

#include <initializer_list>
using std::initializer_list;

#include <stdexcept>
using std::out_of_range;

#include <cassert>

template <typename Object>
class Queue {
public:
    ////////// Big Five ///////
    explicit Queue(int c = 0): size{0}, capacity{c}, pos{new Object[c]}, theFront{pos}, theBack{pos} {}
    Queue(const initializer_list<Object>& il);
    Queue(const Queue& rhs);
    Queue& operator=(const Queue& rhs);
    Queue(Queue&& rhs);
    Queue& operator=(Queue&& rhs);
    ~Queue() { delete [] pos;}


    /////////// Queue API ///////////
    void enqueue(const Object& x);
    Object dequeue();
    Object& front() { return *theFront; }
    const Object& front() const { return *theFront; }
    Object& back() { return *theBack; }
    const Object& back() const { return *theBack; }
    bool empty() const { return size == 0; }
    int sz() { return size; }

private:
    static constexpr double INITIAL_LIST_SPARE = 2;
    int size;
    int capacity;
    Object* pos;
    Object* theFront;
    Object* theBack;
};

////////// Queue implement //////////
template <typename Object>
Queue<Object>::Queue(const initializer_list<Object>& il): Queue(il.size() * INITIAL_LIST_SPARE) {
    for (auto &i: il)
        enqueue(i);
}

template <typename Object>
Queue<Object>::Queue(const Queue& rhs): Queue(rhs.capacity) {
    Object* trace = rhs.theFront;
    int cnt = 0;
    for (int i = 0; i != rhs.size; ++i) {
        // if need come to the array's first pos
        if (trace - rhs.pos + i == rhs.capacity) {
            trace = rhs.pos;
            cnt = i;
        }
        enqueue(*(trace + i - cnt));
    }
}

template <typename Object>
Queue<Object>& Queue<Object>::operator=(const Queue& rhs) {
    Queue cpy = rhs;
    std::swap(*this, cpy);
    return *this;
}
template <typename Object>
Queue<Object>::Queue(Queue&& rhs): size(rhs.size), capacity(rhs.capacity), pos(rhs.pos), theFront(rhs.theFront), theBack(rhs.theBack) {
    rhs.size = 0;
    rhs.theBack = rhs.theFront = rhs.pos = nullptr;
}

template <typename Object>
Queue<Object>& Queue<Object>::operator=(Queue&& rhs) {
    if (this != &rhs) {
        delete [] pos;

        size = rhs.size;
        capacity = rhs.size;
        pos = rhs.pos;
        theFront = rhs.theFront;
        theBack = rhs.theBack;

        rhs.size = 0;
        rhs.pos = rhs.theFront = rhs.theBack = nullptr;
    }
    return *this;
}




template <typename Object>
void Queue<Object>::enqueue(const Object& x) {
    if (size == capacity)
        throw out_of_range("queue was full");
    if (size == 0) {
        ++size;
        assert(theFront == theBack);
        *(theFront) = x;
    }
    else {
        ++size;
        // if ++theBack need came to array's first pos
        if (theBack - pos + 1 == capacity) {
            theBack = pos;
            *(theBack) = x;
        }
        else {
            ++theBack;
            *theBack = x;
        }
    }
}

template <typename Object>
Object Queue<Object>::dequeue() {
    if (size == 0) {
        assert(theFront == theBack);
        throw out_of_range("queue was empty");
    }
    --size;
    Object ret = *theFront;
    // if ++theFront need came to array's first pos
    if (theFront - pos + 1 == capacity) {
        theFront = pos;
    }
    else
        ++theFront;

    return ret;
}


#endif //DS_A_ALGO_IN_CPP_QUEUE_CIRCULAR_ARRAY_H
