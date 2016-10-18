#include <fstream>
#include <iostream>
#include "12-19.cpp"

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ifstream;

int main(int argc, char *argv[]) {
    ifstream fin(argv[1]);
    string line;
    StrBlob sb;
    while (getline(fin, line)) {
        sb.push_back(line);
    }
    for (StrBlobPtr beg = sb.begin(), end = sb.end(); beg != end; beg.incr()) {
        cout << beg.deref() << "\n";
    }

    return 0;
}
