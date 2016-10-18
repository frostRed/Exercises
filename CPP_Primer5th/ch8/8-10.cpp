#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;

int main(int argc, char *argv[]) {
    ifstream ifst(argv[1]);
    vector<string> str_vec;
    if (ifst) {
        string tmp;
        while (getline(ifst, tmp)) {
            str_vec.push_back(tmp);
        }
    }
    ifst.close();

    for (auto &i: str_vec) {
        istringstream iss(i);
        string tmp;
        while (iss >> tmp) {
            std::cout << tmp << std::endl;
        }
    }


    return 0;
}
