#include <list>
#include <string>
#include <vector>

using std::list;
using std::string;
using std::vector;

void fun(list<char *> &cp_li, vector<string> &str_vec) {
    str_vec.assign(cp_li.begin(), cp_li.end());
}
