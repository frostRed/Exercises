//
// Created by paysonl on 16-10-20.
//

#include <cassert>
#include <initializer_list>
using std::initializer_list;

#include <algorithm>


template <typename Object>
class Stack {
private:
    struct Node {
        Object data;
        Node* prev;
        Node* next;
        Node(const Object& d = Object(), Node* p = nullptr, Node* n = nullptr): data{d}, prev{p}, next{n} {}
        Node(const Object&& d, Node* p = nullptr, Node* n = nullptr): data{std::move(d)}, prev{p}, next{n} {}
    };
public:
    class const_iterator {
        friend class Stack<Object>;
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

    class iterator: public const_iterator {
        friend class Stack<Object>;
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


    Stack() { init(); }
    Stack(const initializer_list<Object>& il) {
        init();
        for (auto &i: il)
            push(i);
    }
    ~Stack() {
        clear();
        delete head;
        delete tail;
    }
    Stack(const Stack& rhs) {
        init();
        for (auto &i: rhs)
            push(i);
        //for (auto i = rhs.begin(); i != rhs.end(); ++i)
        //   push_back(*i);
    }
    Stack&operator=(const Stack& rhs) {
        Stack cpy = rhs;
        std::swap(*this, cpy);
        return *this;
    }
    Stack(Stack&& rhs) noexcept : size{rhs.size}, head{rhs.head}, tail{rhs.tail} {
        rhs.size = 0;
        rhs.head = rhs.tail = nullptr;
    }
    Stack&operator=(Stack&& rhs) noexcept {
        if (this != &rhs) {
            clear();
            size = rhs.size;
            head = rhs.head;
            tail = rhs.tail;
            rhs.head = rhs.tail = nullptr;
            // make rhs Empty
            rhs.size = 0;
        }
         /*
        std::swap( size, rhs.size );
        std::swap( head, rhs.head );
        std::swap( tail, rhs.tail );
        */

        return *this;
    }



    int sz() const { return size; }
    bool empty() const { return size == 0; }
    void clear() {
        while (!empty())
            pop();
    }

    ////////// Stack API //////////
    Object& top() { return *begin(); }
    const Object& top() const { return *begin(); }
    void push(const Object& x) {
        insert(begin(), x);
    }
    void push(Object&& x) {
        insert(begin(), std::move(x));
    }
    Object pop() {
        Object retVal = top();
        erase(begin());
        return retVal;
    }
    //////////////////////////////

private:
    iterator begin() { return iterator(head->next); }
    const_iterator begin() const { return const_iterator(head->next); }
    iterator end() { return iterator(tail); }
    const_iterator end() const { return const_iterator(tail); }
    const_iterator cbegin() { return const_iterator(head->next); }
    const_iterator cend() { return const_iterator(tail); }

    iterator insert(iterator ite, const Object& x) {
        Node* p = ite.current;
        ++size;
        return p->prev = p->prev->next = new Node(x, p->prev, p);

    }
    iterator insert(iterator ite, Object&& x) {
        Node* p = ite.current;
        ++size;
        return p->prev = p->prev->next = new Node(std::move(x), p->prev, p);
    }
    iterator erase(iterator ite) {
        Node* p = ite.current;
        iterator retVal(p->next);
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        --size;
        return retVal;
    }
    iterator erase(iterator from, iterator to) {
        for (iterator itr = from; itr != to; ++itr)
            itr = erase(itr);
    }

    int size;
    Node* head;
    Node* tail;
    void init() {
        size = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }

};

int main() {
    Stack<int> l{1, 2, 3, 4};
    auto l2(l);
    l.push(5);
    assert(l.top() == 5);

    auto l3(std::move(l2));
    l3 = std::move(l);
    assert(l3.top() == 5);
    l3.pop();
    assert(l3.top() == 4);

    assert(l3.pop() == 4);
    assert(l3.top() == 3);

}
