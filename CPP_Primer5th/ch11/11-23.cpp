#include <map>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::multimap;

int main() {
    using family = multimap<string, vector<string>>;
    family recoder = { {"AB", {"CD", "EF"}},
                        {"GH", {}}
                    };
    //recoder["GH"].push_back("MN");
    recoder.insert({"GH", {"MN", "WX"}});

    return 0;
}
