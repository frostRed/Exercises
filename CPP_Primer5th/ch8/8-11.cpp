#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std:string;
using std:vector;
using std::ifstream;
using std::istringstream;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main(int argc, char *argv[]) {
    ifstream ifst(argv[1]);
    vector<PersonInfo> people;

    if (ifst) {
        string line, word;
        istringstream iss;

        while (getline(ifst, line)) {
            PersonInfo info;
            iss.str(line);
            iss >> word;
            info.name = word;
            while (iss >> word) {
                info.phones.push_back(word);
            }
            people.push_back(info);
        }
    }

    return 0;
}
