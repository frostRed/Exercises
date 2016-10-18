#include <fstream>
#include <vector>
#include <string>
#include <iterator>
using std::vector;
using std::string;
using std::ifstream;
using std::istream_iterator;

int main(int argc, char *argv[]) {
    ifstream fin(argv[1]);
    istream_iterator<string> in_ite(fin), eof;

    vector<string> vs;
    while (in_ite != eof) {
        vs.push_back(*in_ite++);
    }

    return 0;
}
