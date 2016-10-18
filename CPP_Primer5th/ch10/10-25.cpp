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
using namespace std::placeholders;

void elimDups(vector<string> &svec) {
    sort(svec.begin(), svec.end());
    auto end_uni = unique(svec.begin(), svec.end());
    svec.erase(end_uni, svec.end());

}
bool check_size(const string &s, string::size_type sz) {
    return s.size() < sz;
}

void biggies(vector<string> &svec, vector<string>::size_type sz) {
    elimDups(svec);
    stable_sort(svec.begin(), svec.end(),
            [](const string &s1, const string &s2) {return s1.size() < s2.size();});

    auto first_false_ite = partition(svec.begin(), svec.end(), bind(check_size, _1, sz));

    auto count = svec.end() - first_false_ite;
    cout << count << endl;
    for_each(first_false_ite, svec.end(),
            [](const string &s){cout << s << endl;});
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
