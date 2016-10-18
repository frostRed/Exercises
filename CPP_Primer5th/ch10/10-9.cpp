#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
using std::string;
using std::vector;
using std::ifstream;

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

    sort(svec.begin(), svec.end());
    auto end_uni = unique(svec.begin(), svec.end());
    svec.erase(end_uni, svec.end());
    for (auto &i: svec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
