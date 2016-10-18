#include <iostream>
#include <string>
using std::string;

string make_plural(size_t ctr, const string &word, const string &ending = "s") {
    return (ctr > 1) ? word + ending : word;
}
int main() {
    string str1{"success"}, str2{"failure"};
    std::cout << make_plural(0, str1, "es") << "\t" << make_plural(2, str1, "es") << std::endl;
    std::cout << make_plural(0, str2) << "\t" << make_plural(2, str2) << std::endl;

    return 0;
}
