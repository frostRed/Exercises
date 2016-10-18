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
    SizeComp(size_t l, size_t u): low(l), up(u) {}

    bool operator()(string &s) {
        return s.size() >= low && s.size() <= up;
    }

private:
    size_t low;
    size_t up;
};

int main(int argc, char *argv[]) {
    vector<string> vs;
    ifstream fin(argv[1]);
    string word;
    while (fin >> word) vs.push_back(word);

    auto cnt = count_if(vs.begin(), vs.end(), SizeComp(1, 9));
    std::cout << cnt << std::endl;
    
    cnt = count_if(vs.begin(), vs.end(), SizeComp(10, 90));
    std::cout << cnt << std::endl;
}
