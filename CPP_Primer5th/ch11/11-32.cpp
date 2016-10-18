#include <map>
#include <string>
#include <iostream>
using std::multimap;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    multimap<string, string> recodes{{"abc", "fjeo"},
                                    {"efg", "fjfjeeo"},
                                    {"abc", "fjeoajf"},
                                    {"xyz", "fjoefje"},
                                    {"efg", "ajboefoe"} };

    string author = "abc";
    multimap<string, string>::iterator ret;
    while ((ret = recodes.find(author)) != recodes.end()) {
        recodes.erase(ret);
    }

    string curr_author = recodes.begin()->first;
    multimap<string, string>::iterator beg, end;
    while ((beg = recodes.lower_bound(curr_author)) != 
            (end = recodes.upper_bound(curr_author))) {
        cout << beg->first << ": " << beg->second << endl;
        // 并非单个时
        if (++beg != end) {
            for (; beg != end; ++beg) {
                cout << "        " << beg->second << endl;
            }

        }
        // 没遍历完时
        if (end != recodes.end()) {
            curr_author = end->first;
        } else {
            break;
        }
    }

    return 0;
}
