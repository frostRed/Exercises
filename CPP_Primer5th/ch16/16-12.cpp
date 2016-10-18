#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

template <typename T> class BlobPtr;

template <typename T>
class Blob {
public:
    friend class BlobPtr<T>;

    using value_type = T;
    using size_type = typename std::vector<T>::size_type;

    Blob();
    Blob(std::initializer_list<T> il);

    BlobPtr<T> begin();
    BlobPtr<T> end();

    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}

    void push_back(const T &t) {data->push_back(t);}
    void pop_back();

    T &front();
    const T &front() const;
    T &back();
    const T &back() const;


private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const T &msg) const;
};

template <typename T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()) {}

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il): data(std::make_shared<std::vector<T>>(il)) {}

template <typename T>
void Blob<T>::check(size_type i, const T &msg) const {
    if (i >= data->size()) {
        throw std::out_of_range(msg);
    }
}
template <typename T>
T &Blob<T>::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}
template <typename T>
T &Blob<T>::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}
template <typename T>
const T &Blob<T>::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}
template <typename T>
const T &Blob<T>::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}
template <typename T>
void Blob<T>::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

//////////////////////////////////////
//       BlobPtr            /////////
////////////////////////////////////

template <typename T>
class BlobPtr {
public:
    using size_type = typename std::vector<T>::size_type;
    BlobPtr(): curr(0) {}
    BlobPtr(Blob<T> &a, size_type sz = 0): wptr(a.data), curr(sz) {}

    T &deref() const;
    BlobPtr &incr();

private:
    std::shared_ptr<std::vector<T>> check(size_t i, const T& msg) const;
    std::weak_ptr<std::vector<T>> wptr;
    size_type curr;
};

template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(size_t i, const T& msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("umbound StrBlobPtr");
    }
    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}
template <typename T>
T &BlobPtr<T>::deref() const {
    auto sp = check(curr, "dereference past end");
    return (*sp)[curr];
}
template <typename T>
BlobPtr<T> &BlobPtr<T>::incr() {
    check(curr, "increment past end of StrBLobPtr");
    ++curr;
    return *this;
}

template <typename T>
inline BlobPtr<T> Blob<T>::begin() {
        return StrBlobPtr(*this);
}
template <typename T>
inline BlobPtr<T> Blob<T>::end() {
        return BlobPtr<T>(*this, data->size());
}
