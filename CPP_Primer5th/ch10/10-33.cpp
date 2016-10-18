#include <fstream>
#include <iterator>
using std::ifstream;
using std::ofstream;
using std::istream_iterator;
using std::ostream_iterator;

int main(int argc, char *argv[]) {
    ifstream fin(argv[1]);
    ofstream fout_odd(argv[2]);
    ofstream fout_even(argv[3]);
    
    istream_iterator<int> in_iter(fin), eof;
    ostream_iterator<int> out_iter_odd(fout_odd, " ");
    ostream_iterator<int> out_iter_even(fout_even, "\n");

    while (in_iter != eof) {
        if (*in_iter % 2) {
            *out_iter_odd++ = *in_iter++;
        } else {
            *out_iter_even++ = *in_iter++;
        }
    }
    
    return 0;
}
