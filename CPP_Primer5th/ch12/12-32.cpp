#include "12-32.h"

StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}

StrBlob::StrBlob(std::initializer_list<string> il): data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size()) {
        throw std::out_of_range(msg);
    }
}
string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}
string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}
const string &StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}
const string &StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}
void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

shared_ptr<vector<string>> StrBlobPtr::check(size_type i, const string &msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("umbound StrBlobPtr");
    }
    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}
string &StrBlobPtr::deref() const {
    auto sp = check(curr, "dereference past end");
    return (*sp)[curr];
}
StrBlobPtr &StrBlobPtr::incr() {
    check(curr, "increment past end of StrBLobPtr");
    ++curr;
    return *this;
}
StrBlobPtr &StrBlobPtr::incr_n(size_type n) {
    for (size_type i = 0; i != n; ++i) {
        check(curr, "increment past end of StrBLobPtr");
        ++curr;
    }
    return *this;
}

inline StrBlobPtr StrBlob::begin() {
        return StrBlobPtr(*this);
}
inline StrBlobPtr StrBlob::end() {
        return StrBlobPtr(*this, data->size());
}
inline const StrBlobPtr StrBlob::cbegin() const {
        return StrBlobPtr(*this);
}
inline const StrBlobPtr StrBlob::cend() const{
        return StrBlobPtr(*this, data->size());
}



//TextQuery::TextQuery(ifstream &infile): text(new vector<string>) {
TextQuery::TextQuery(ifstream &infile): text(StrBlob()) {
    string line;
    size_type linenum = 0;
    while (getline(infile, line)) {
        text.push_back(line);
        istringstream iss(line);
        string word;
        while (iss >> word) {
            auto &linesSet = w2LineNum[word];
            if (!linesSet) {
                linesSet.reset(new set<size_type>);
            } 
            linesSet->insert(linenum);
        }
        ++linenum;
    }
}
ostream &print(ostream &os, const QueryResult &qr) {
    os << qr.looked_word << " occurs " << qr.linenumSet->size() << " " << "times" << endl;

    for (auto num: *qr.linenumSet) {
        os << "\t(line " << num + 1 << "( ";
        StrBlobPtr p = qr.text.cbegin();
        os << p.incr_n(num).deref() << endl; 
    }
    return os;
}

QueryResult TextQuery::query(const string &s) const {
    static shared_ptr<set<size_type>> nodata(new set<size_type>);
    auto loc = w2LineNum.find(s);
    if (loc == w2LineNum.end()) {
        return QueryResult(s, nodata, text);
    }
    else {
        return QueryResult(s, loc->second, text);
    }
}

void runQueries(ifstream &infile) {
    TextQuery tq(infile);
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;
    }
}

int main(int argc, char *argv[]) {
    ifstream fin(argv[1]);
    runQueries(fin);
    
    return 0;
}
