#include <vector>
using std::vector;

bool fun(vector<int>::const_iterator beg, vector<int>::const_iterator end, const int val) {
    while (beg != end) {
        if (*beg == val) {
            return true;
        }
    }
    return false;
}
