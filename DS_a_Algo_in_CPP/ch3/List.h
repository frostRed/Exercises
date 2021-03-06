//
// Created by paysonl on 16-10-21.
//

#ifndef DS_A_ALGO_IN_CPP_LIST_H
#define DS_A_ALGO_IN_CPP_LIST_H

#include <initializer_list>
using std::initializer_list;

// use std::move
#include <algorithm>


template <typename Object>
class List {
private:
    struct Node;
public:
    class const_iterator;
    class iterator;
    class const_reverse_iterator;
    class reverse_iterator;


    List();
    List(const initializer_list<Object>& il);
    ~List();
    List(const List& rhs);
    List& operator=(const List& rhs);
    List(List&& rhs) noexcept;
    List& operator=(List&& rhs) noexcept;


    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    const_iterator cbegin();
    const_iterator cend();

    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;
    reverse_iterator rend();
    const_reverse_iterator rend() const;
    const_reverse_iterator crbegin();
    const_reverse_iterator crend();


    int sz() const;
    bool empty() const;
    // clear all elements
    void clear();

    Object& front();
    const Object& front() const;
    Object& back();
    const Object& back() const;
    void push_front(const Object& x);
    void push_front(Object&& x) ;
    void push_back(const Object& x);
    void push_back(Object&& x);
    void pop_front();
    void pop_back();


    iterator insert(iterator ite, const Object& x);
    iterator insert(iterator ite, Object&& x);
    iterator erase(iterator ite);
    iterator erase(iterator from, iterator to);

    void splice(iterator position, List<Object>& lst);


private:
    int size;
    Node* head;
    Node* tail;
    void init();
};

/////////////////////////////////
//////// Implements ////////////
///////////////////////////////

template <typename Object>
class List<Object>::Node {
    // must make List as friend
    friend class List<Object>;
    Object data;
    Node* prev;
    Node* next;
    Node(const Object& d = Object(), Node* p = nullptr, Node* n = nullptr): data{d}, prev{p}, next{n} {}
    Node(const Object&& d, Node* p = nullptr, Node* n = nullptr): data{std::move(d)}, prev{p}, next{n} {}
};


//////////// Iterator ////////////
template <typename Object>
class List<Object>::const_iterator {
    friend class List<Object>;
    // arguments are base class reference, so iterator instance can also use these
    friend bool operator==(const const_iterator& lhs, const const_iterator& rhs) {
        return lhs.current == rhs.current;
    }
    friend bool operator!=(const const_iterator& lhs, const const_iterator& rhs) {
        return !(lhs == rhs);
    }
    friend int operator-(const const_iterator&lhs, const const_iterator& rhs) {
        // lhs must be ahead of rhs
        int ret = 0;
        auto left = rhs;
        while (left != lhs) {
            ++ left;
            ++ret;
        }
        return ret;

    }

public:
    const_iterator(): current{nullptr} {}

    const Object& operator*() const { return retrieve(); }
    const_iterator& operator++() {
        current = current->next;
        return *this;
    }
    const_iterator& operator++(int) {
        const_iterator old = *this;
        ++(*this);
        return old;
    }
    const_iterator& operator--() {
        current = current->prev;
        return *this;
    }
    const_iterator& operator--(int) {
        const_iterator old = *this;
        --(*this);
        return old;
    }
    const_iterator operator+(int k) const {
        auto ret = *this;
        for (int i = 0; i != k; ++i)
            ++ret;
        return ret;
    }

protected:
    Node* current;
    Object& retrieve() const { return current->data; }
    const_iterator(Node* p): current{p} {}
};


template <typename Object>
class List<Object>::iterator: public const_iterator {
    friend class List<Object>;
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
    iterator operator+(int k) const {
        auto ret = *this;
        for (int i = 0; i != k; ++i)
            ++ret;
        return ret;
    }

protected:
    iterator(Node *p): const_iterator(p) {}
};


//////////// reverse iterator ////////////
template <typename Object>
class List<Object>::const_reverse_iterator: public const_iterator {
    friend class List<Object>;

public:
    const_reverse_iterator()  {}

    const_reverse_iterator& operator++() {
        this->current = this->current->prev;
        return *this;
    }
    const_reverse_iterator& operator++(int) {
        const_iterator old = *this;
        ++(*this);
        return old;
    }
    const_reverse_iterator& operator--() {
        this->current = this->current->next;
        return *this;
    }
    const_reverse_iterator& operator--(int) {
        const_iterator old = *this;
        --(*this);
        return old;
    }
    const_reverse_iterator operator+(int k) const {
        auto ret = *this;
        for (int i = 0; i != k; ++i)
            ++ret;
        return ret;
    }

protected:
    const_reverse_iterator(Node* p): const_iterator{p} {}
};


template <typename Object>
class List<Object>::reverse_iterator: public const_reverse_iterator {
    friend class List<Object>;
public:
    reverse_iterator() {}
    Object& operator*() {
        return const_reverse_iterator::retrieve();
    }
    const Object& operator*() const {
        return const_reverse_iterator::operator*();
    }

    reverse_iterator& operator++() {
        //current = current->next;
        this->current = this->current->prev;
        return *this;
    }
    reverse_iterator&operator++(int) {
        iterator old = *this;
        ++(*this);
        return old;
    }
    reverse_iterator&operator--() {
        //current = current->next;
        this->current = this->current->next;
        return *this;
    }
    reverse_iterator&operator--(int) {
        iterator old = *this;
        --(*this);
        return old;
    }
    reverse_iterator operator+(int k) const {
        auto ret = *this;
        for (int i = 0; i != k; ++i)
            ++ret;
        return ret;
    }

protected:
    reverse_iterator(Node *p): const_reverse_iterator(p) {}
};

///////////////// List methods //////////////////////
////////////////////////////////////////////////////
template <typename Object>
void List<Object>::init() {
    size = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}

template <typename Object>
List<Object>::List() { init(); }

template <typename Object>
List<Object>::List(const initializer_list<Object>& il) {
    init();
    for (auto &i: il)
        push_back(i);
}

template <typename Object>
List<Object>::~List() {
    clear();
    delete head;
    delete tail;
}

template <typename Object>
List<Object>::List(const List& rhs) {
    init();
    for (auto &i: rhs)
        push_back(i);
}

template <typename Object>
List<Object>& List<Object>::operator=(const List& rhs) {
    List cpy = rhs;
    std::swap(*this, cpy);
    return *this;
}

template <typename Object>
List<Object>::List(List&& rhs) noexcept : size{rhs.size}, head{rhs.head}, tail{rhs.tail} {
    rhs.size = 0;
    rhs.head = rhs.tail = nullptr;
}

template <typename Object>
List<Object>& List<Object>::operator=(List&& rhs) noexcept {
    if (this != &rhs) {
        // remember free all nodes, include head and tail
        clear();
        delete head;
        delete tail;

        size = rhs.size;
        head = rhs.head;
        tail = rhs.tail;
        rhs.head = rhs.tail = nullptr;
        // make rhs Empty
        rhs.size = 0;
    }

    return *this;
}

///////////// iterator methods //////////////
template <typename Object>
typename List<Object>::iterator List<Object>::begin() { return iterator(head->next); }

template <typename Object>
typename List<Object>::const_iterator List<Object>::begin() const { return const_iterator(head->next); }

template <typename Object>
typename List<Object>::iterator List<Object>::end() { return iterator(tail); }

template <typename Object>
typename List<Object>::const_iterator List<Object>::end() const { return iterator(tail); }

template <typename Object>
typename List<Object>::const_iterator List<Object>::cbegin() { return const_iterator(head->next); }

template <typename Object>
typename List<Object>::const_iterator List<Object>::cend() { return const_iterator(tail); }

////////////// reverse iterator methods //////////////
template <typename Object>
typename List<Object>::reverse_iterator List<Object>::rbegin() { return reverse_iterator(tail->prev); }

template <typename Object>
typename List<Object>::const_reverse_iterator List<Object>::rbegin() const { return const_reverse_iterator(tail->prev); }

template <typename Object>
typename List<Object>::reverse_iterator List<Object>::rend() { return reverse_iterator(head); }

template <typename Object>
typename List<Object>::const_reverse_iterator List<Object>::rend() const { return reverse_iterator(head); }

template <typename Object>
typename List<Object>::const_reverse_iterator List<Object>::crbegin() { return const_reverse_iterator(tail->prev); }

template <typename Object>
typename List<Object>::const_reverse_iterator List<Object>::crend() { return const_reverse_iterator(head); }


///////////////////////////
template <typename Object>
int List<Object>::sz() const { return size; }

template <typename Object>
bool List<Object>::empty() const { return size == 0; }

template <typename Object>
void List<Object>::clear() {
    while (!empty())
        pop_front();
}

template <typename Object>
Object& List<Object>::front() { return *begin(); }

template <typename Object>
const Object& List<Object>::front() const { return *begin(); }

template <typename Object>
Object& List<Object>::back() { return *--end(); }

template <typename Object>
const Object& List<Object>::back() const { return *--end(); }

template <typename Object>
void List<Object>::push_front(const Object& x) {
    insert(begin(), x);
}

template <typename Object>
void List<Object>::push_front(Object&& x) {
    insert(begin(), std::move(x));
}

template <typename Object>
void List<Object>::push_back(const Object& x) {
    insert(end(), x);
}

template <typename Object>
void List<Object>::push_back(Object&& x) {
    insert(end(), std::move(x));
}

template <typename Object>
void List<Object>::pop_front() {
    erase(begin());
}

template <typename Object>
void List<Object>::pop_back() {
    erase(--end());
}

template <typename Object>
typename List<Object>::iterator List<Object>::insert(iterator ite, const Object& x) {
    Node* p = ite.current;
    ++size;
    return p->prev = p->prev->next = new Node(x, p->prev, p);
}

template <typename Object>
typename List<Object>::iterator List<Object>::insert(iterator ite, Object&& x) {
    Node* p = ite.current;
    ++size;
    return p->prev = p->prev->next = new Node(std::move(x), p->prev, p);
}

template <typename Object>
typename List<Object>::iterator List<Object>::erase(iterator ite) {
    Node* p = ite.current;
    iterator retVal(p->next);
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    --size;
    return retVal;
}

template <typename Object>
typename List<Object>::iterator List<Object>::erase(iterator from, iterator to) {
    for (iterator itr = from; itr != to; ++itr)
        itr = erase(itr);
}

template <typename Object>
void List<Object>::splice(iterator position, List<Object> &lst) {
    Node* pos = position.current;

    pos->prev->next = lst.head->next;
    lst.head->next->prev = pos->prev;

    pos->prev = lst.tail->prev;
    lst.tail->prev->next = pos;

    lst.head->next = lst.tail;
    lst.tail->prev = lst.head;

    size += lst.size;
    lst.size = 0;
}



#endif //DS_A_ALGO_IN_CPP_LIST_H
