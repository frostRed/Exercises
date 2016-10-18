#include <forward_list>
using std::forward_list;

forward_list<int> &fun(forward_list<int> &ifl) {
    auto pre = ifl.before_begin();
    auto curr = ifl.begin();
    while (curr != ifl.end()) {
        if (*curr % 2) {
            curr = ifl.erase_after(curr);
        } else {
            pre = curr;
            ++curr;
        }
    }
    return ifl;
}
