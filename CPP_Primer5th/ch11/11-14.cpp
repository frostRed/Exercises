#include <map>
#include <string>
#include <vector>
#include <utility>
using std::string;
using std::vector;
using std::map;
using std::pair;

int main() {
    using family = map<string, vector<pair<string, string>>>;
    family recoder = { {"AB", 
                            { {"CD", "10.1"}, {"EF", "10.2"} }
                       },
                       {"GH",
                            { }
                       }
                    };
    recoder["GH"].push_back({"MN", "10.10"});

    return 0;
}
