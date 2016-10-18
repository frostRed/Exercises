#include <map>
#include <string>
using std::multimap;
using std::string;

int main() {
    multimap<string, string> recodes{{"abc", "fjeo"},
                                    {"efg", "fjfjeeo"},
                                    {"abc", "fjeoajf"} };

    string author = "abc";
    multimap<string, string>::iterator ret;
    while ((ret = recodes.find(author)) != recodes.end()) {
        recodes.erase(ret);
    }


    return 0;
}
