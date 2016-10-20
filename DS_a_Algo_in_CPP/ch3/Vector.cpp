//
// Created by paysonl on 16-10-20.
//
#include <cassert>
#include <initializer_list>
using std::initializer_list;

#include <algorithm>

template <typename Object, typename... Args>
class Vector {
public:
    explicit Vector(int initsize = 0): size{initsize},
                                       capacity{initsize + SPARE_CAPACITY}, objects{new Object[capacity]} {}
    /*
    Vector(const Args&... rest):Vector(0) {
        push_back(rest...);
    }
     */
    Vector(const initializer_list<Object>& il): Vector(il.size()) {
        for (int i = 0; i != il.size(); ++i)
            objects[i] = *(il.begin() + i);
    }
    Vector(const Vector& rhs): size(rhs.size), capacity(rhs.capacity),
                               objects{new Object[capacity]} {
        for (int i = 0; i != size; ++i)
            objects[i] = rhs.objects[i];
    }
    Vector&operator=(const Vector& rhs) {
        Vector cpy = rhs;
        std::swap(*this, cpy);
        return *this;
    }
    ~Vector() {delete [] objects;}
    Vector(Vector&& rhs): size{rhs.size}, capacity{rhs.capacity}, objects{rhs.objects} {
        rhs.objects = nullptr;
        rhs.size = rhs.capacity = 0;
    }
    Vector&operator=(Vector&& rhs) {
        if (this != &rhs) {
            size = rhs.size;
            capacity = rhs.size;
            objects = rhs.objects;
            rhs.objects = nullptr;
            rhs.size = rhs.capacity = 0;
        }
        return *this;
    }

    void resize(int newSize) {
        if (newSize > capacity)
            reserve(newSize * 2);
        size = newSize;
    }
    void reserve(int newCapacity) {
        if (newCapacity < size)
            return;
        Object* newArray = new Object[newCapacity];
        for (int i = 0; i != size; ++i)
            newArray[i] = objects[i];
        capacity = newCapacity;
        std::swap(objects, newArray);
        delete [] newArray;
    }

    Object&operator[](int index) {
        return objects[index];
    }
    const Object&operator[](int index) const {
        return objects[index];
    }
    bool empty() const { return size == 0; }
    int sz() const { return size; }
    int cap() const { return capacity; }

    void push_back(const Object& x) {
        if (size == capacity)
            reserve(2 * capacity + 1);
        objects[size++] = x;
    }
    void pop_back() {
        --size;
    }
    const Object& back() const {
        return objects[size - 1];
    }

    using iterator = Object*;
    using const_iterator = const Object*;

    iterator begin() { return &objects[0]; }
    const_iterator begin() const { return &objects[0]; }
    iterator end() { return &objects[size]; }
    const_iterator end() const { return  &objects[size]; }
    const_iterator cbegin() { return &objects[0]; }
    const_iterator cend() {return &objects[size]; }


    static const int SPARE_CAPACITY = 16;
private:
    int size;
    int capacity;
    Object* objects;
};

int main() {
    Vector<int> v(10);
    assert(v.sz() == 10);

    Vector<double> v2{1.5, 2, 3, 4, 5};
    assert(*(v2.begin()) == 1.5);

    auto v3(v2);
    v3 = v2;
    auto v4(std::move(v3));
    v4 = Vector<double>{4, 6, 8};
}
