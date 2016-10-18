#include "16-58-1.h"
allocator<string> StrVec::alloc = allocator<string>();



void StrVec::push_back(const string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}
pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}
void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p != elements; ) alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);

    }
}

StrVec::StrVec(const StrVec &s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}
StrVec::~StrVec() {free();}
StrVec &StrVec::operator=(const StrVec &rhs) {
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}

void StrVec::reallocate() {
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

void StrVec::reserve(size_t n) {
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
void StrVec::resize(size_t n) {
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

template <typename... Args>
void StrVec::empalce_back(Args&& ...rest) {
    chk_n_alloc();
    alloc.construct(first_free++, std::forward<Args>(rest)...);
}


