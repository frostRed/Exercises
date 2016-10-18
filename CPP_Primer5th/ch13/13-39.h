#include <memory>
#include <string>
#include <utility>
using std::string;
using std::pair;
using std::allocator;

class StrVec {
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
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
