#include <vector>

using std::vector;

bool eq_iv(const vector<int> &iv1, const vector<int> &iv2) {
    if (iv1.size() != iv2.size()) {
        return false;
    } else {
        for (decltype(iv1.size()) i = 0; i != iv1.size(); ++i) {
            if (iv1[i] != iv2[i]) {
                return false;
            }
        }
        return true;
    }
}
