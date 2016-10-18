#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;

int main(int argc, char *argv[]) {
    string ascender("bdfhijklt");
    string descender("gjqpy");
    vector<string> vs;
    string file(argv[1]);
    ifstream fin(file);
    if (fin) {
        string word;
        while (fin >> word) {
            if (word.find_first_of(ascender) == string::npos &&
                    word.find_first_of(descender) == string::npos) {
                vs.push_back(word);
            }
        }
    }
    string ret;
    string::size_type len = 0;
    for (auto &i: vs) {
        if (i.size() > len) {
            len = i.size();
            ret = i;
        }
    }
    cout << ret << endl;
    return 0;
}
