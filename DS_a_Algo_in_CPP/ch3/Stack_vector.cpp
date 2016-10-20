//
// Created by paysonl on 16-10-20.
//
#include <cassert>
#include <initializer_list>
using std::initializer_list;

#include <algorithm>

template <typename Object, typename... Args>
class Stack {
public:
    explicit Stack(int initsize = 0): size{initsize},
                                       capacity{initsize + SPARE_CAPACITY}, objects{new Object[capacity]} {}
    /*
    Stack(const Args&... rest):Stack(0) {
        push_back(rest...);
    }
     */
    Stack(const initializer_list<Object>& il): Stack(il.size()) {
        for (int i = 0; i != il.size(); ++i)
            objects[i] = *(il.begin() + i);
    }
    Stack(const Stack& rhs): size(rhs.size), capacity(rhs.capacity),
                               objects{new Object[capacity]} {
        for (int i = 0; i != size; ++i)
            objects[i] = rhs.objects[i];
    }
    Stack&operator=(const Stack& rhs) {
        Stack cpy = rhs;
        std::swap(*this, cpy);
        return *this;
    }
    ~Stack() {delete [] objects;}
    Stack(Stack&& rhs): size{rhs.size}, capacity{rhs.capacity}, objects{rhs.objects} {
        rhs.objects = nullptr;
        rhs.size = rhs.capacity = 0;
    }
    Stack&operator=(Stack&& rhs) {
        if (this != &rhs) {
            size = rhs.size;
            capacity = rhs.size;
            objects = rhs.objects;
            rhs.objects = nullptr;
            rhs.size = rhs.capacity = 0;
        }
        return *this;
    }

    bool empty() const { return size == 0; }
    //int sz() const { return size; }
    //int cap() const { return capacity; }

    /////////// Stack API //////////////
    void push(const Object& x) {
        if (size == capacity)
            reserve(2 * capacity + 1);
        objects[size++] = x;
    }
    Object pop() {
        return objects[size--];
    }
    const Object& top() const {
        return objects[size - 1];
    }
    //////////////////////////////////////




    static const int SPARE_CAPACITY = 16;
private:
    int size;
    int capacity;
    Object* objects;
    
    using iterator = Object*;
    using const_iterator = const Object*;
    
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
    
    iterator begin() { return &objects[0]; }
    const_iterator begin() const { return &objects[0]; }
    iterator end() { return &objects[size]; }
    const_iterator end() const { return  &objects[size]; }
    const_iterator cbegin() { return &objects[0]; }
    const_iterator cend() {return &objects[size]; }

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
