#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob {
public:
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;

    using size_type = std::vector<std::string>::size_type;

    StrBlob();
    StrBlob(std::initializer_list<std::string> il);

    StrBlobPtr begin();
    StrBlobPtr end();
    ConstStrBlobPtr cbegin() const;
    ConstStrBlobPtr cend() const;

    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}

    void push_back(const std::string &t) {data->push_back(t);}
    void pop_back();

    std::string &front();
    const std::string &front() const;
    std::string &back();
    const std::string &back() const;


private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il): data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, const std::string &msg) const {
    if (i >= data->size()) {
        throw std::out_of_range(msg);
    }
}
std::string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}
std::string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}
const std::string &StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}
const std::string &StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}
void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

class StrBlobPtr {
public:
    using size_type = std::vector<std::string>::size_type;
    StrBlobPtr(): curr(0) {}
    StrBlobPtr(StrBlob &a, size_type sz = 0): wptr(a.data), curr(sz) {}

    std::string &deref() const;
    StrBlobPtr &incr();

private:
    std::shared_ptr<std::vector<std::string>> check(size_t i, const std::string& msg) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    size_type curr;
};
std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(size_type i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("umbound StrBlobPtr");
    }
    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}
std::string &StrBlobPtr::deref() const {
    auto sp = check(curr, "dereference past end");
    return (*sp)[curr];
}
StrBlobPtr &StrBlobPtr::incr() {
    check(curr, "increment past end of StrBLobPtr");
    ++curr;
    return *this;
}

inline StrBlobPtr StrBlob::begin() {
        return StrBlobPtr(*this);
}
inline StrBlobPtr StrBlob::end() {
        return StrBlobPtr(*this, data->size());
}


class ConstStrBlobPtr {
public:
    using size_type = std::vector<std::string>::size_type;
    ConstStrBlobPtr(): curr(0) {}
    ConstStrBlobPtr(const StrBlob &a, size_type sz = 0): wptr(a.data), curr(sz) {}

    std::string &deref() const;
    ConstStrBlobPtr &incr();

private:
    std::shared_ptr<std::vector<std::string>> check(size_t i, const std::string& msg) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    mutable size_type curr;
};
std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(size_type i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("umbound StrBlobPtr");
    }
    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}
std::string &ConstStrBlobPtr::deref() const {
    auto sp = check(curr, "dereference past end");
    return (*sp)[curr];
}
ConstStrBlobPtr &ConstStrBlobPtr::incr() {
    check(curr, "increment past end of StrBLobPtr");
    ++curr;
    return *this;
}

inline ConstStrBlobPtr StrBlob::cbegin() const{
        return ConstStrBlobPtr(*this);
}
inline ConstStrBlobPtr StrBlob::cend() const {
        return ConstStrBlobPtr(*this, data->size());
}
