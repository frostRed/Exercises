#include <memory>
#include <utility>
#include <initializer_list>
using std::pair;
using std::allocator;
using std::initializer_list;

template <typename T>
class Vec {
public:
    Vec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
    explicit Vec(initializer_list<T> il) {
        auto data = alloc_n_copy(il.begin(), il.end());
        elements = data.first;
        first_free = cap = data.second;
    }
    Vec(const Vec &);
    Vec &operator=(const Vec &);
    ~Vec();

    template <typename... Args>
    void emplace_back(Args&& ...);

    void push_back(const T &);
    inline size_t size() const;
    inline size_t capacity() const;
    void reserve(size_t);
    void resize(size_t);

    inline T *begin() const;
    inline T *end() const;

private:
    static allocator<T> alloc;
    void chk_n_alloc() {
        if (size() == capacity()) reallocate();
    }
    pair<T*, T*> alloc_n_copy(const T*, const T*);
    void free();
    void reallocate();
    T *elements;
    T *first_free;
    T *cap;
};

template <typename T>
inline size_t Vec<T>::size() const {
    return first_free - elements;
}
template <typename T>
inline size_t Vec<T>::capacity() const {
    return cap - elements;
}
template <typename T>
inline T *Vec<T>::begin() const {
    return elements;
}
template <typename T>
inline T *Vec<T>::end() const {
    return first_free;
}
