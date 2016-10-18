//
// Created by paysonl on 16-10-18.
//
#include <cassert>
#include <stdexcept>
using std::out_of_range;

template <typename Comparables> class OrderedCollection;
template <typename Comparables> void swap(OrderedCollection<Comparables>&, OrderedCollection<Comparables>&);

template <typename Comparables>
class OrderedCollection {
    friend void swap<Comparables>(OrderedCollection<Comparables>& lhs, OrderedCollection<Comparables>& rhs);

public:
    explicit OrderedCollection(int s = 0): arr(new Comparables[s]), sz(0), cap(s) {}
    ~OrderedCollection() {delete [] arr;}
    OrderedCollection(const OrderedCollection& coll): arr(new Comparables[coll.sz]), sz(coll.sz), cap(coll.cap) {
        for (int i = 0; i != coll.sz; ++i)
            *(arr + i) = *(coll.arr + i);
    }
    OrderedCollection& operator=(OrderedCollection rhs) {
        swap(*this, rhs);
        return *this;
    }
    OrderedCollection(OrderedCollection&& coll) noexcept : arr(coll.arr), sz(coll.sz), cap(coll.cap) {
        coll.arr = nullptr;
    }
    OrderedCollection& operator=(OrderedCollection&& rhs) noexcept {
       if (this != &rhs) {
           delete [] arr;
           arr = rhs.arr;
           sz = rhs.sz;
           cap = rhs.cap;
           rhs = nullptr;
       }
        return *this;
    }


    bool isEmpty() const {return sz == 0;}

    void makeEmpty() {
        delete [] arr;
        arr = new Comparables[0];
        cap = sz = 0;
    }
    void insert(const Comparables& obj) {
        if (isEmpty()) {
            delete [] arr;
            arr = new Comparables [1];
            arr[sz] = obj;
            ++sz;
            ++cap;
        } else if (sz == cap){
            Comparables* old_arr = arr;
            arr = new Comparables [cap * 2];
            for (int i = 0; i != cap; ++i)
                *(arr + i) = *(old_arr + i);
            delete [] old_arr;
            arr[sz] = obj;
            ++sz;
            cap *= 2;
            order();
        } else {
            arr[sz] = obj;
            ++sz;
        }
    }
    Comparables remove(Comparables* pos) {
        Comparables ret = * pos;
        for (auto i = pos + 1; i != arr + sz; ++i)
            *(i - 1) = *i;
        --sz;
        return ret;
    }
    bool contains(const Comparables& obj) const {
        for (int i = 0; i != sz; ++i)
            if (*(arr + i) == obj)
                return true;
        return false;
    }

    Comparables findMin() const {
        if (isEmpty())
            throw out_of_range("OrderedCollections is empty");
        return *arr;
    }
    Comparables findMax() const {
        if (isEmpty())
            throw out_of_range("OrderedCollections is empty");
        return *(arr + sz - 1);
    }

private:
    void order() {
        for (int i = sz -1; i > 0; --i) {
            Comparables right = *(arr + i);
            Comparables left = *(arr + i - 1);
            if (right < left) {
                Comparables tmp = right;
                right = left;
                left = tmp;
            }
        }
    }
    Comparables* arr;
    int sz;
    int cap;
};

void swap(int& i1, int& i2);
template <typename Comparables>
void swap(OrderedCollection<Comparables>& lhs, OrderedCollection<Comparables>& rhs) {
    Comparables* tmp = rhs.arr;
    rhs.arr = lhs.arr;
    lhs.arr = tmp;

    swap(lhs.sz, rhs.sz);
    swap(lhs.cap, rhs.cap);
}

void swap(int& i1, int& i2) {
    int tmp = i1;
    i1 = i2;
    i2 = tmp;
}


int main() {
    OrderedCollection<int> c;
    assert(c.isEmpty());
    c.insert(1);
    assert(c.contains(1));
    c.insert(2);
    assert(!c.contains(3));
    c.insert(3);
    assert(c.findMax() == 3);
    assert(c.findMin() == 1);
    c.makeEmpty();
    assert(c.isEmpty());
}
