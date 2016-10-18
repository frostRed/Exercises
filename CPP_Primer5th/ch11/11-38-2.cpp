#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include <sstream>

using std::ifstream;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::istringstream;
using std::runtime_error;

const string &transform(const string &s, const unordered_map<string, string> &m);
unordered_map<string, string> buildMap(ifstream &map_file);
void word_transform(ifstream &map_file, ifstream &input);

int main(int argc, char *argv[]) {
    ifstream map_file(argv[1]), input(argv[2]);

    word_transform(map_file, input);


    return 0;
}


const string &transform(const string &s, const unordered_map<string, string> &m) {
    auto ite = m.find(s);
    if (ite != m.cend()) {
        return ite->second;
    }
    else {
        return s;
    }
}
unordered_map<string, string> buildMap(ifstream &map_file) {
    string word, line;
    unordered_map<string, string> rules;
    while (map_file >> word && getline(map_file, line)) {
        if (line.size() > 1) {
            rules[word] = line.substr(1);
        }
        else {
            throw runtime_error("no rules");
        }
    }
    return rules;
}
void word_transform(ifstream &map_file, ifstream &input) {
    unordered_map<string, string> rules = buildMap(map_file);

    string line;
    while (getline(input, line)) {
        bool firstword = true;
        istringstream issin(line);
        string word;

        while (issin >> word) {
            if (firstword) {
                firstword = false;
            }
            else {
                cout << " ";
            }

            cout << transform(word, rules);
        }
        cout << endl;
    }
}
