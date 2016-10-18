#include <string>
#include <iostream>
#include <iostream>
using std::string;

string &fun(string &name, const string &prefix, const string &surfix) {
    name.insert(0, prefix);
    name.insert(name.size(), surfix);
    return name;
}
int main() {
    string name = "John";
    std::cout << fun(name, "Mr.", "Jr.") << std::endl;
    return 0;
}
