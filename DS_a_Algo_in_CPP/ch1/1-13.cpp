//
// Created by paysonl on 16-10-18.
//
#include <cassert>

template <typename Objects> class Collection;
template <typename Objects> void swap(Collection<Objects>&, Collection<Objects>&);

template <typename Objects>
class Collection {
    friend void swap<Objects>(Collection<Objects>& lhs, Collection<Objects>& rhs);

public:
    explicit Collection(int s = 0): arr(new Objects[s]), sz(0), cap(s) {}
    ~Collection() {delete [] arr;}
    Collection(const Collection& coll): arr(new Objects[coll.sz]), sz(coll.sz), cap(coll.cap) {
        for (int i = 0; i != coll.sz; ++i)
            *(arr + i) = *(coll.arr + i);
    }
    Collection& operator=(Collection rhs) {
        swap(*this, rhs);
        return *this;
    }
    Collection(Collection&& coll) noexcept : arr(coll.arr), sz(coll.sz), cap(coll.cap) {
        coll.arr = nullptr;
    }
    Collection& operator=(Collection&& rhs) noexcept {
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
        arr = new Objects[0];
        cap = sz = 0;
    }
    void insert(const Objects& obj) {
        if (isEmpty()) {
            delete [] arr;
            arr = new Objects [1];
            arr[sz] = obj;
            ++sz;
            ++cap;
        } else if (sz == cap){
            Objects* old_arr = arr;
            arr = new Objects [cap * 2];
            for (int i = 0; i != cap; ++i)
                *(arr + i) = *(old_arr + i);
            delete [] old_arr;
            arr[sz] = obj;
            ++sz;
            cap *= 2;
        } else {
            arr[sz] = obj;
            ++sz;
        }
    }
    Objects remove(Objects* pos) {
        Objects ret = * pos;
        for (auto i = pos + 1; i != arr + sz; ++i)
            *(i - 1) = *i;
        --sz;
        return ret;
    }
    bool contains(const Objects& obj) const {
        for (int i = 0; i != sz; ++i)
            if (*(arr + i) == obj)
                return true;
        return false;
    }

private:
    Objects* arr;
    int sz;
    int cap;
};

void swap(int& i1, int& i2);
template <typename Objects>
void swap(Collection<Objects>& lhs, Collection<Objects>& rhs) {
    Objects* tmp = rhs.arr;
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
    Collection<int> c;
    assert(c.isEmpty());
    c.insert(1);
    assert(c.contains(1));
    c.insert(2);
    assert(!c.contains(3));
    c.makeEmpty();
    assert(c.isEmpty());
}
