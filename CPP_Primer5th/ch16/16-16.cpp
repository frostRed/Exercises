#include "16-16.h"

template <typename T>
allocator<T> Vec<T>::alloc = allocator<T>();



template <typename T>
void Vec<T>::push_back(const T &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}
template <typename T>
pair<T *, T *> Vec<T>::alloc_n_copy(const T *b, const T *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}
template <typename T>
void Vec<T>::free() {
    if (elements) {
        for (auto p = first_free; p != elements; ) alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);

    }
}

template <typename T>
Vec<T>::Vec(const Vec<T> &s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}
template <typename T>
Vec<T>::~Vec() {free();}

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec<T> &rhs) {
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}

template <typename T>
void Vec<T>::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);

    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

template <typename T>
void Vec<T>::reserve(size_t n) {
    if (n > capacity()) {
        auto newcapacity = n;
        auto newdata = alloc.allocate(newcapacity);

        auto dest = newdata;
        auto elem = elements;
        for (size_t i = 0; i != size(); ++i) {
            alloc.construct(dest++, std::move(*elem++));
        }
        free();
        elements = newdata;
        first_free = dest;
        cap = elements + newcapacity;
    }
}

template <typename T>
void Vec<T>::resize(size_t n) {
    if (n < size()) {
        size_t cnt = size() - n;
        for (auto p = first_free; p != first_free - cnt; ) {
            alloc.destroy(--p);
        }
        first_free -= cnt;
    } else if (n > size() && n <= capacity()) {
        size_t cnt = n - size();
        for (auto i = 0; i != cnt; ++i) {
            alloc.construct(first_free++, "");
        }
    } else if (n > capacity()) {
        auto newcapacity = n;
        auto newdata = alloc.allocate(newcapacity);

        auto dest = newdata;
        auto elem = elements;
        for (size_t i = 0; i != size(); ++i) {
            alloc.construct(dest++, std::move(*elem++));
        }
        free();
        elements = newdata;
        first_free = dest;
        cap = elements + newcapacity;
    }
}
