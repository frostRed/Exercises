//
// Created by paysonl on 16-10-20.
//

#ifndef DS_A_ALGO_IN_CPP_VECTOR_H
#define DS_A_ALGO_IN_CPP_VECTOR_H

#include <initializer_list>
using std::initializer_list;

// use std::move
#include <algorithm>

#include <stdexcept>
using std::out_of_range;
using std::logic_error;

template <typename Object, typename ... Args>
class Vector {
public:
    using iterator = Object*;
    using const_iterator = const Object*;

    explicit Vector(int initsize = 0): size{initsize},
                                       capacity{initsize + SPARE_CAPACITY}, objects{new Object[capacity]} {}
    Vector(const initializer_list<Object>& il): Vector(il.size()) {
        // Can I complement same function by using Args unpack?
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
        if (index < 0 || index >= size)
            throw out_of_range("indxing out of range");
        return objects[index];
    }
    const Object&operator[](int index) const {
        if (index < 0 || index >= size)
            throw out_of_range("indxing out of range");
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
        if (empty())
            throw logic_error("vector was empty");
        --size;
    }
    iterator insert(iterator ite, const Object& x) {
        if (size == capacity)
            reserve(2 * capacity + 1);
        ++size;
        for (iterator pos = end() - 1; pos >= ite; -- pos) {
            *(pos + 1) = *pos;
        }
        *ite = x;

        return ite;
    }
    iterator erase(iterator ite) {
        if (empty())
            throw logic_error("vector was empty");
        if (ite == end())
            throw out_of_range("iterator is out of range");
        --size;
        for (iterator pos = ite + 1; ite != end(); ++ite) {
            *(pos - 1) = *pos;
        }
        return ite;
    }
   /*
    const Object& back() const {
        return objects[size - 1];
    }
    */




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


#endif //DS_A_ALGO_IN_CPP_LIST_H
