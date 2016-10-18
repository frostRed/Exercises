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

void elimDups(vector<string> &svec) {
    sort(svec.begin(), svec.end());
    auto end_uni = unique(svec.begin(), svec.end());
    svec.erase(end_uni, svec.end());

}

void biggies(vector<string> &svec, vector<string>::size_type sz) {
    elimDups(svec);
    stable_sort(svec.begin(), svec.end(),
            [](const string &s1, const string &s2) {return s1.size() < s2.size();});

    auto false_ite = stable_partition(svec.begin(), svec.end(),
            [sz](const string &s) {return s.size() >= sz;});

    auto count = false_ite - svec.begin();
    for_each(svec.begin(), false_ite,
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
