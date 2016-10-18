#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
using std::string;
using std::vector;
using std::ifstream;

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

void elimDups(vector<string> &svec) {
    sort(svec.begin(), svec.end());
    auto end_uni = unique(svec.begin(), svec.end());
    svec.erase(end_uni, svec.end());

    stable_sort(svec.begin(), svec.end(), isShorter);
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

    elimDups(svec);

    for (auto &i: svec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
