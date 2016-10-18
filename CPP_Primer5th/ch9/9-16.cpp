#include <vector>
#include <list>

using std::vector;
using std::list;

bool eq_iv(const list<int> &il, const vector<int> &iv) {
    if (il.size() != iv.size()) {
        return false;
    } else {
        const vector<int> iv2(il.begin(), il.end());
        for (decltype(iv.size()) i = 0; i != iv.size(); ++i) {
            if (iv[i] != iv2[i]) {
                return false;
            }
        }
        return true;
    }
}
