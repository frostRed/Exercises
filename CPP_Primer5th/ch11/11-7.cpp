#include <map>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::map;

int main() {
    using family = map<string, vector<string>>;
    family recoder = { {"AB", {"CD", "EF"}},
                        {"GH", {}}
                    };
    recoder["GH"].push_back("MN");

    return 0;
}
