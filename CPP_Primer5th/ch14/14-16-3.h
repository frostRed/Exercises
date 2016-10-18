#include <memory>
#include <string>
#include <utility>
#include <initializer_list>
using std::string;
using std::pair;
using std::allocator;
using std::initializer_list;

class StrVec {
    friend bool operator==(const StrVec &, const StrVec &);
    friend bool operator!=(const StrVec &, const StrVec &);
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
    explicit StrVec(initializer_list<string> il) {
        auto data = alloc_n_copy(il.begin(), il.end());
        elements = data.first;
        first_free = cap = data.second;
    }
    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &);
    ~StrVec();

    void push_back(const string &);
    inline size_t size() const;
    inline size_t capacity() const;
    void reserve(size_t);
    void resize(size_t);

    inline string *begin() const;
    inline string *end() const;

private:
    static allocator<string> alloc;
    void chk_n_alloc() {
        if (size() == capacity()) reallocate();
    }
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void reallocate();
    string *elements;
    string *first_free;
    string *cap;
};


inline size_t StrVec::size() const {
    return first_free - elements;
}
inline size_t StrVec::capacity() const {
    return cap - elements;
}
inline string *StrVec::begin() const {
    return elements;
}
inline string *StrVec::end() const {
    return first_free;
}
