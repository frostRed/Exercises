#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
#include <fstream>
using std::ifstream;
#include <sstream>
using std::istringstream;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <map>
using std::map;
#include <set>
using std::set;
#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <tuple>
using std::tuple;
using std::get;


using QueryResult = tuple<string, shared_ptr<set<vector<string>::size_type>>, shared_ptr<vector<string>>>;

class TextQuery {
public:
    using size_type = vector<string>::size_type;

    TextQuery() = default;
    TextQuery(ifstream &infile);
    QueryResult query(const string &s) const;

private:
    shared_ptr<vector<string>> text;
    map<string, shared_ptr<set<size_type>>> w2LineNum;

};
TextQuery::TextQuery(ifstream &infile): text(new vector<string>) {
    string line;
    size_type linenum = 0;
    while (getline(infile, line)) {
        text->push_back(line);
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

/*
class QueryResult {
    friend ostream &print(ostream &, const QueryResult &);
public:
    using size_type = vector<string>::size_type;
    QueryResult(const string &s, shared_ptr<set<size_type>> lnSet, shared_ptr<vector<string>> lt):
        looked_word(s), linenumSet(lnSet), text(lt) {}

private:
    string looked_word;
    shared_ptr<set<size_type>> linenumSet;
    shared_ptr<vector<string>> text;

};
*/
ostream &print(ostream &os, const QueryResult &qr) {
    os << get<0>(qr) << " occurs" << get<1>(qr)->size() << " times" << endl;

    for (auto num: *get<1>(qr)) {
        os << "\t(line " << num + 1 << "( " << *(get<2>(qr)->begin() + num) << endl; 
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
