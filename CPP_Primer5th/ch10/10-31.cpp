#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
    istream_iterator<int> in_ite(cin), eof;
    ostream_iterator<int> out_ite(cout, "\n");


    vector<int> vi;
    while (in_ite != eof) {
        vi.push_back(*in_ite++);
    }
    sort(vi.begin(), vi.end());
    unique_copy(vi.begin(), vi.end(), out_ite);

    return 0;
}
