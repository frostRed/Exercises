#include <vector>
using std::vector;

using iv_const_ite = vector<int>::const_iterator;
using iv_ite = vector<int>::iterator;

iv_const_ite fun(iv_const_ite beg, iv_const_ite end, const int val) {
    while (beg != end) {
        if (*beg == val) {
            return beg;
        }
    }
    return beg;
}

/*
iv_ite fun(iv_ite beg, iv_ite end, const int val) {
    auto ret = fun(const_cast<iv_const_ite>(beg), const_cast<iv_const_ite>(end), val);
    return const_cast<iv_ite>(ret);
}
*/
