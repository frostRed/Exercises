#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <initializer_list>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::set;
using std::ifstream;
using std::ostream;
using std::istringstream;
using std::shared_ptr;
using std::weak_ptr;
using std::make_shared;
using std::initializer_list;


class StrBlobPtr;
class StrBlob {
public:
    friend class StrBlobPtr;

    using size_type = vector<string>::size_type;

    StrBlob();
    StrBlob(initializer_list<string> il);

    StrBlobPtr begin();
    StrBlobPtr end();
    const StrBlobPtr cbegin() const;
    const StrBlobPtr cend() const;

    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}

    void push_back(const string &t) {data->push_back(t);}
    void pop_back();

    string &front();
    const string &front() const;
    string &back();
    const string &back() const;


private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};


class StrBlobPtr {
public:
    using size_type = vector<string>::size_type;
    StrBlobPtr(): curr(0) {}
    StrBlobPtr(const StrBlob &a, size_type sz = 0): wptr(a.data), curr(sz) {}

    string &deref() const;
    StrBlobPtr &incr();
    StrBlobPtr &incr_n(size_type n);

private:
    shared_ptr<vector<string>> check(size_t i, const string& msg) const;
    weak_ptr<vector<string>> wptr;
    size_type curr;
};



class QueryResult;
class TextQuery {
public:
    using size_type = vector<string>::size_type;

    TextQuery() = default;
    TextQuery(ifstream &infile);
    QueryResult query(const string &s) const;

private:
    //shared_ptr<vector<string>> text;
    StrBlob text;
    map<string, shared_ptr<set<size_type>>> w2LineNum;

};


class QueryResult {
    friend ostream &print(ostream &, const QueryResult &);
public:
    using size_type = vector<string>::size_type;
    QueryResult(const string &s, shared_ptr<set<size_type>> lnSet, StrBlob lt):
        looked_word(s), linenumSet(lnSet), text(lt) {}

private:
    string looked_word;
    shared_ptr<set<size_type>> linenumSet;
    //shared_ptr<vector<string>> text;
    StrBlob text;

};

