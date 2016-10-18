#include <string>
#include <vector>
#include <iostream>
#include <utility>
using std::cin;
using std::string;
using std::vector;
using std::pair;

int main() {
    vector<pair<string, int>> mVec;
    string s;
    int val;
    while (cin >> s >> val) {
        mVec.push_back(make_pair(s, val));

        mVec.push_back({s, val});

        pair<string, int> p = {s, val};
        mVec.push_back(p);
    }
    return 0;

}
