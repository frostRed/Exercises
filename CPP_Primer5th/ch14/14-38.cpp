#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::ifstream;

class SizeComp {
public:
    SizeComp(size_t n): sz(n) {}

    bool operator()(string &s) {
        return s.size() == sz;
    }

private:
    size_t sz;
};

int main(int argc, char *argv[]) {
    vector<string> vs;
    ifstream fin(argv[1]);
    string word;
    while (fin >> word) vs.push_back(word);

    for (int i = 0; i != 10; ++i) {
        auto cnt = count_if(vs.begin(), vs.end(), SizeComp(i + 1));
        std::cout << cnt << std::endl;
    }
    
}
