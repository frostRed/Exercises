#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;

bool comp(const string &s1) {
    return s1.size() >= 13;
}

int main(int argc, char *argv[]) {
    vector<string> svec;
    string word;
    string fname = argv[1];
    ifstream fin(fname);
    if (fin) {
        while (fin >> word) {
            svec.push_back(word);
        }
    }
    auto false_ite = partition(svec.begin(), svec.end(), comp);
    for (auto beg = svec.cbegin(); beg != false_ite; ++beg) {
        cout << *beg << " ";
    }
    cout << endl;

    return 0;


}
