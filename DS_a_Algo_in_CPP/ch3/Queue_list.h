//
// Created by paysonl on 16-10-21.
//

#ifndef DS_A_ALGO_IN_CPP_QUEUE_H
#define DS_A_ALGO_IN_CPP_QUEUE_H

#include <initializer_list>
using std::initializer_list;

// use std::move
#include <algorithm>


template <typename Object>
class Queue {
private:
    struct Node;
public:
    class const_iterator;
    class iterator;


    Queue();
    Queue(const initializer_list<Object>& il);
    ~Queue();
    Queue(const Queue& rhs);
    Queue& operator=(const Queue& rhs);
    Queue(Queue&& rhs) noexcept;
    Queue& operator=(Queue&& rhs) noexcept;



    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    const_iterator cbegin();
    const_iterator cend();


    int sz() const;
    bool empty() const;
    void clear();

    Object& front();
    const Object& front() const;
    Object& back();
    const Object& back() const;
    
    ////////// Queue API ///////
    void enqueue(const Object& x);
    void enqueue(Object&& x);
    void dequeue();
    ///////////////////////////


    iterator insert(iterator ite, const Object& x);
    iterator insert(iterator ite, Object&& x);
    iterator erase(iterator ite);
    iterator erase(iterator from, iterator to);


private:
    int size;
    Node* head;
    Node* tail;
    void init();
};

///////////////////////////////
///////////////////////////////
///////////////////////////////

template <typename Object>
class Queue<Object>::Node {
    // must make Queue as friend
    friend class Queue<Object>;
    Object data;
    Node* prev;
    Node* next;
    Node(const Object& d = Object(), Node* p = nullptr, Node* n = nullptr): data{d}, prev{p}, next{n} {}
    Node(const Object&& d, Node* p = nullptr, Node* n = nullptr): data{std::move(d)}, prev{p}, next{n} {}
};


////////////////////////
template <typename Object>
class Queue<Object>::const_iterator {
    friend class Queue<Object>;
    friend bool operator==(const const_iterator& lhs, const const_iterator& rhs) {
        return lhs.current == rhs.current;
    }
    friend bool operator!=(const const_iterator& lhs, const const_iterator& rhs) {
        return !(lhs == rhs);
    }


public:
    const_iterator(): current{nullptr} {}

    const Object&operator*() const { return retrieve(); }
    const_iterator&operator++() {
        current = current->next;
        return *this;
    }
    const_iterator&operator++(int) {
        const_iterator old = *this;
        ++(*this);
        return old;
    }
    const_iterator&operator--() {
        current = current->prev;
        return *this;
    }
    const_iterator&operator--(int) {
        const_iterator old = *this;
        --(*this);
        return old;
    }

protected:
    Node* current;
    Object& retrieve() const { return current->data; }
    const_iterator(Node* p): current{p} {}
};


template <typename Object>
class Queue<Object>::iterator: public const_iterator {
    friend class Queue<Object>;
public:
    iterator() {}
    Object&operator*() {
        return const_iterator::retrieve();
    }
    const Object&operator*() const {
        return const_iterator::operator*();
    }

    iterator&operator++() {
        //current = current->next;
        this->current = this->current->next;
        return *this;
    }
    iterator&operator++(int) {
        iterator old = *this;
        ++(*this);
        return old;
    }
    iterator&operator--() {
        //current = current->next;
        this->current = this->current->prev;
        return *this;
    }
    iterator&operator--(int) {
        iterator old = *this;
        --(*this);
        return old;
    }
protected:
    iterator(Node *p): const_iterator(p) {}
};


/////////// Queue implement ////////////
template <typename Object>
void Queue<Object>::init() {
    size = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}

template <typename Object>
Queue<Object>::Queue() { init(); }

template <typename Object>
Queue<Object>::Queue(const initializer_list<Object>& il) {
    init();
    for (auto &i: il)
        enqueue(i);
}

template <typename Object>
Queue<Object>::~Queue() {
    clear();
    delete head;
    delete tail;
}

template <typename Object>
Queue<Object>::Queue(const Queue& rhs) {
    init();
    for (auto &i: rhs)
        enqueue(i);
}

template <typename Object>
Queue<Object>& Queue<Object>::operator=(const Queue& rhs) {
    Queue cpy = rhs;
    std::swap(*this, cpy);
    return *this;
}

template <typename Object>
Queue<Object>::Queue(Queue&& rhs) noexcept : size{rhs.size}, head{rhs.head}, tail{rhs.tail} {
    rhs.size = 0;
    rhs.head = rhs.tail = nullptr;
}

template <typename Object>
Queue<Object>& Queue<Object>::operator=(Queue&& rhs) noexcept {
    if (this != &rhs) {
        clear();
        size = rhs.size;
        head = rhs.head;
        tail = rhs.tail;
        rhs.head = rhs.tail = nullptr;
        // make rhs Empty
        rhs.size = 0;
    }

    return *this;
}
///////////////////////

template <typename Object>
typename Queue<Object>::iterator Queue<Object>::begin() { return iterator(head->next); }

template <typename Object>
typename Queue<Object>::const_iterator Queue<Object>::begin() const { return const_iterator(head->next); }

template <typename Object>
typename Queue<Object>::iterator Queue<Object>::end() { return iterator(tail); }

template <typename Object>
typename Queue<Object>::const_iterator Queue<Object>::end() const { return iterator(tail); }

template <typename Object>
typename Queue<Object>::const_iterator Queue<Object>::cbegin() { return const_iterator(head->next); }

template <typename Object>
typename Queue<Object>::const_iterator Queue<Object>::cend() { return const_iterator(tail); }


////////////////////////
template <typename Object>
int Queue<Object>::sz() const { return size; }

template <typename Object>
bool Queue<Object>::empty() const { return size == 0; }

template <typename Object>
void Queue<Object>::clear() {
    while (!empty())
        dequeue();
}

template <typename Object>
Object& Queue<Object>::front() { return *begin(); }

template <typename Object>
const Object& Queue<Object>::front() const { return *begin(); }

template <typename Object>
Object& Queue<Object>::back() { return *--end(); }

template <typename Object>
const Object& Queue<Object>::back() const { return *--end(); }

///////////// Queue API /////////////

template <typename Object>
void Queue<Object>::enqueue(const Object& x) {
    insert(end(), x);
}

template <typename Object>
void Queue<Object>::enqueue(Object&& x) {
    insert(end(), std::move(x));
}

template <typename Object>
void Queue<Object>::dequeue() {
    erase(begin());
}

//////////////////////////

template <typename Object>
typename Queue<Object>::iterator Queue<Object>::insert(iterator ite, const Object& x) {
    Node* p = ite.current;
    ++size;
    return p->prev = p->prev->next = new Node(x, p->prev, p);
}

template <typename Object>
typename Queue<Object>::iterator Queue<Object>::insert(iterator ite, Object&& x) {
    Node* p = ite.current;
    ++size;
    return p->prev = p->prev->next = new Node(std::move(x), p->prev, p);
}

template <typename Object>
typename Queue<Object>::iterator Queue<Object>::erase(iterator ite) {
    Node* p = ite.current;
    iterator retVal(p->next);
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    --size;
    return retVal;
}

template <typename Object>
typename Queue<Object>::iterator Queue<Object>::erase(iterator from, iterator to) {
    for (iterator itr = from; itr != to; ++itr)
        itr = erase(itr);
}


#endif //DS_A_ALGO_IN_CPP_QUEUE_H
