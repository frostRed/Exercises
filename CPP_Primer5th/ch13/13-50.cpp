#include "13-49-2.h"
#include <cstring>
#include <vector>
#include <iostream>

allocator<char> String::alloc = allocator<char>();

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
String::String(const String &s):
    elements(alloc_n_copy(s.begin(), s.end()).first),
    first_free(elements + s.size()),
    cap(elements + s.size()) {}

String::String(String &&s) noexcept:
    elements(s.elements), first_free(s.first_free), cap(s.cap) {
        std::cout << "String(String &&)" << std::endl;
        s.elements = s.first_free = s.cap = nullptr;
}

String &String::operator=(String &&rhs) noexcept {
    std::cout << "operator=(String &&)" << std::endl;
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
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

int main() {
    std::vector<String> v;
    std::cout << v.size() << " " << v.capacity() << std::endl;
    v.push_back("a");
    std::cout << v.size() << " " << v.capacity() << std::endl;
    v.push_back("b");
    std::cout << v.size() << " " << v.capacity() << std::endl;
    v.push_back("c");
    std::cout << v.size() << " " << v.capacity() << std::endl;
}
