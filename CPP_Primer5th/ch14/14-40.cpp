#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;

void elimDups(vector<string> &svec);

class Compare {
public:
    bool operator()(const string &s1, const string &s2) {
        return s1.size() < s2.size();
    }
};
class MoreThan {
public:
    MoreThan() = default;
    MoreThan(size_t n): sz(n) {}
    bool operator()(const string &s) {
        return s.size() > sz;
    }
private:
    size_t sz;
};
class Print {
public:
    Print(std::ostream &o = std::cout): os(o) {}
    void operator()(const string &s) {
        std::cout << s << std::endl;
    }
private:
    std::ostream &os;
};
void biggies(vector<string> &svec, vector<string>::size_type sz) {
    elimDups(svec);
    stable_sort(svec.begin(), svec.end(), Compare());

    auto first_true_ite = find_if(svec.begin(), svec.end(), MoreThan(sz));

    auto count = svec.end() - first_true_ite;
    for_each(first_true_ite, svec.end(), Print());

}

int main(int argc, char *argv[])  {
    vector<string> svec;
    string word;
    string fname = argv[1];
    ifstream fin(fname);
    if (fin) {
        while (fin >> word) {
            svec.push_back(word);
        }
    }

    string::size_type br = stoi(string(argv[2]));

    biggies(svec, br);
    return 0;
}

void elimDups(vector<string> &svec) {
    sort(svec.begin(), svec.end());
    auto end_uni = unique(svec.begin(), svec.end());
    svec.erase(end_uni, svec.end());
}
