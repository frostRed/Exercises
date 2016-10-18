#include <string>
#include <forward_list>

using std::string;
using std::forward_list;

void fun(forward_list<string> &strFl, string &s1, string &s2) {
    auto pre = strFl.before_begin();
    auto curr = strFl.begin();
    while (curr != strFl.end() && *curr != s1) {
        ++curr;
        ++pre;
    };
    strFl.insert_after(pre, s2);
}
