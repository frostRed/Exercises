#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using std::ifstream;
using std::cout;
using std::endl;
using std::string;
using std::list;

int main(int argc, char *argv[]) {
    ifstream fin(argv[1]);
    list<string> ls;
    string word;
    while (fin >> word) {
        ls.push_back(word);
    }

    ls.sort();
    ls.unique();

    for (auto i: ls) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
