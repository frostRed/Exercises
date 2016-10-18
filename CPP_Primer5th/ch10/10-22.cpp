#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::ostream;
using namespace std::placeholders;

void fRead(ifstream &fin, const string &fname, vector<string> &words) {
    fin.open(fname);
    string word;
    while (fin >> word) {
        words.push_back(word);
    }
}


void elimDups(vector<string> &svec) {
    sort(svec.begin(), svec.end());
    auto end_uni = unique(svec.begin(), svec.end());
    svec.erase(end_uni, svec.end());
}

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

bool ck_size(const string &s, string::size_type sz) {
    return s.size() > sz;
}

ostream &print(ostream &os, const string &s, char c) {
    os << s << c;
    return os;
}

void biggies(vector<string> &svec, vector<string>::size_type sz) {
    elimDups(svec);
    stable_sort(svec.begin(), svec.end(), isShorter);

    auto true_ite = find_if(svec.begin(), svec.end(), bind(ck_size, _1, sz));

    auto count = svec.size() - count_if(svec.begin(), svec.end(), bind(ck_size, _1, sz));
    cout << count << endl;

    for_each(svec.begin(), true_ite, bind(print, ref(cout), _1, '\n'));

}

int main(int argc, char *argv[])  {
    vector<string> svec;
    string fname = argv[1];
    ifstream fin;
    fRead(fin, fname, svec);

    string::size_type sz = stoi(string(argv[2]));
    biggies(svec, sz);


    return 0;
}
