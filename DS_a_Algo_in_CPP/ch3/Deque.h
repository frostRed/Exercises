//
// Created by paysonl on 16-10-22.
//

#ifndef DS_A_ALGO_IN_CPP_DEQUE_H
#define DS_A_ALGO_IN_CPP_DEQUE_H

#include <algorithm>

#include <initializer_list>
using std::initializer_list;

template <typename> class Deque;

template <typename Object>
class Node {
    friend class Deque<Object>;
private:
    Object data;
    Node* prev;
    Node* next;
    Node(const Object& d = Object(), Node* p = nullptr, Node* n = nullptr):
            data{d}, prev{p}, next{n} {}
    Node(Object&& d, Node* p = nullptr, Node* n = nullptr):
            data{d}, prev{p}, next{n} {}
};

template <typename Object>
class Deque {
private:
    Node<Object>* head;
    Node<Object>* tail;
    int sz;
    void init();
    void clear();

public:
    Deque();
    Deque(const initializer_list<Object>& il);
    Deque(const Deque& de);
    Deque&operator=(const Deque& rhs);
    Deque(Deque&& de) noexcept ;
    Deque&operator=(Deque&& rhs) noexcept ;
    ~Deque();

    void push(const Object& x);
    void push(Object&& x) ;
    void pop();
    void inject(const Object& x);
    void inject(Object&& x);
    void eject();

    Object& front() { return head->next->data; }
    const Object& front() const { return head->next->data; }
    Object& back() { return tail->prev->data; }
    const Object& back() const { return tail->prev->data; }

    int size() { return sz; }
    bool empty() { return sz == 0; }
};

template <typename Object>
void Deque<Object>::init() {
    sz = 0;
    head = new Node<Object>;
    tail = new Node<Object>;
    head->next = tail;
    tail->prev = head;
}

template <typename Object>
void Deque<Object>::clear() {
    sz = 0;
    while (sz != 0)
        pop();
};

template <typename Object>
Deque<Object>::Deque() {
    init();
}

template <typename Object>
Deque<Object>::Deque(const initializer_list<Object> &il) {
    init();
    for (auto &i: il)
        push(i);
}

template <typename Object>
Deque<Object>::Deque(const Deque &de) {
    init();
    for (auto beg = de.head->next; beg != de.tail; beg = beg->next)
        // keep order
        inject(beg->data);
}

template <typename Object>
Deque<Object>::Deque(Deque &&de) noexcept: sz{de.sz}, head{de.head}, tail{de.tail} {
    de.sz = 0;
    de.head = de.tail = nullptr;
}

template <typename Object>
Deque<Object>::~Deque() {
    clear();
    delete head;
    delete tail;
}

template <typename Object>
Deque<Object>& Deque<Object>::operator=(const Deque &rhs) {
    auto cpy = rhs;
    std::swap(*this, cpy);
    return *this;
}

template <typename Object>
Deque<Object>& Deque<Object>::operator=(Deque &&rhs) noexcept {
    if (this != &rhs) {
        clear();
        delete head;
        delete tail;
        sz = rhs.sz;
        head = rhs.head;
        tail = rhs.tail;

        rhs.sz = 0;
        rhs.head = rhs.tail = nullptr;
    }
    return *this;
}

template <typename Object>
void Deque<Object>::push(const Object &x) {
    ++sz;
    Node<Object>* newNode = new Node<Object>(x, head, head->next);

    head->next = head->next->prev = newNode;
}

template <typename Object>
void Deque<Object>::push(Object &&x) {
    ++sz;
    Node<Object>* newNode = new Node<Object>(std::move(x), head, head->next);

    head->next = head->next->prev = newNode;
}

template <typename Object>
void Deque<Object>::pop() {
    Node<Object>* delPos = head->next;
    --sz;

    delPos->next->prev = head;
    head->next = delPos->next;
    delete delPos;
}

template <typename Object>
void Deque<Object>::inject(const Object &x) {
    ++sz;
    Node<Object>* newNode = new Node<Object>(x, tail->prev, tail);

    tail->prev = tail->prev->next = newNode;
}

template <typename Object>
void Deque<Object>::inject(Object &&x) {
    ++sz;
    Node<Object>* newNode = new Node<Object>(std::move(x), tail->prev, tail);

    tail->prev = tail->prev->next = newNode;
}

template <typename Object>
void Deque<Object>::eject() {
    Node<Object>* delPos = tail->prev;

    delPos->prev->next = tail;
    tail->prev = delPos->prev;
    delete delPos;
}

#endif //DS_A_ALGO_IN_CPP_DEQUE_H
