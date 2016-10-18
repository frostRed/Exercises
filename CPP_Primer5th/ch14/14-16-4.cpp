#include "14-16-4.h"
#include <cstring>

allocator<char> String::alloc = allocator<char>();

bool operator==(const String &lhs, const String &rhs) {
    if (lhs.size () != rhs.size()) {
        return false;
    } else {
        for (size_t i = 0; i != lhs.size(); ++i) {
            if (*(lhs.elements + i) != *(rhs.elements + i)) {
                return false;
            }
        }
        return true;
    }
}


void String::push_back(const char ch) {
    chk_n_alloc();
    alloc.construct(first_free++, ch);
}
pair<char*, char*> String::alloc_n_copy(const char *b, const char *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}
void String::free() {
    if (elements) {
        for (auto p = first_free; p != elements; ) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}
String::String(const char *ch) {
    const char *beg = ch;
    const char *end = ch + strlen(ch);
    auto newdata = alloc_n_copy(beg, end);
    elements = newdata.first;
    first_free = cap = newdata.second;
}
String::String(const String &s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}
String::~String() {
    free();
}
String &String::operator=(const String &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void String::reallocate() {
    size_t newcapacity = size() ? 2 * size() : 1;
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
