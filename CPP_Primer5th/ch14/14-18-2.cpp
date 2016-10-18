#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

class StrBlobPtr;
class StrBlob {
    friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);
public:
    friend class StrBlobPtr;

    using size_type = std::vector<std::string>::size_type;

    StrBlob();
    StrBlob(std::initializer_list<std::string> il);

    StrBlobPtr begin();
    StrBlobPtr end();

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
    friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
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

bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
    return lhs.data == rhs.data;
}
bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs == rhs);
}
bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
    return *lhs.data < *rhs.data;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.wptr.lock() == rhs.wptr.lock() &&
           lhs.curr == rhs.curr;
}
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs == rhs);
}
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    
}
