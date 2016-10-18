#include <memory>
#include <utility>

using std::allocator;
using std::pair;
using std::uninitialized_copy;

class String {
    friend bool operator==(const String &, const String &);
    friend bool operator!=(const String &, const String &);

public:
    String(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
    String(const char *);
    String(const String &);
    String &operator=(const String &);
    ~String();

    void push_back(const char);
    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}

    char *begin() const {return elements;}
    char *end() const {return first_free;}

private:
    char *elements;
    char *first_free;
    char *cap;

    void free();
    void reallocate();
    pair<char *, char *> alloc_n_copy(const char *, const char *);
    void chk_n_alloc() {
        if (size() == capacity()) reallocate();
    }
    static allocator<char> alloc;

};
