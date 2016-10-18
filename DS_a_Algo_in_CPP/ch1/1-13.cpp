//
// Created by paysonl on 16-10-18.
//

template <typename Objects>
class Collection {
    friend void swap(Collection<Objects>& lhs, Collection<Objects>& rhs);

public:
    Collection(int s = 1): arr(new Objects[s]), sz(s) {}
    ~Collection() {delete [] arr;}
    Collection(const Collection& coll): arr(new Objects[coll.sz]) {
        for (int i = 0; i != coll.sz; ++i)
            *(arr + i) = *(coll.arr + i);
    }
    Collection& operator=(Collection rhs) {
        swap(*this, rhs);
        return *this;
    }
    Collection(const Collection&& coll): arr


    int size() {return sz;}

private:
    Objects* arr;
    int sz;
};

void swap(Collection& lhs, Collection& rhs) {
    Objects* tmp = rhs.arr;
    rhs.arr = lhs.arr;
    lhs.arr = tmp;
    std::swap(lhs.sz, rhs.sz);
}
