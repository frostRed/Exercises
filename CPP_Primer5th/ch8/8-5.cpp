#include <fstream>
#include <vector>
#include <string>
using std::ifstream;
using std::vector;
using std::string;

vector<string>& fun(string &fname, vector<string> &strv) {
    ifstream ifstre(fname);
    if (ifstre) {
        string tmp;
        while (ifstre >> tmp) {
            strv.push_back(tmp);
        }
    }

    return strv;
}


