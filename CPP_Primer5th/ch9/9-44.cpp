#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

void fun(string &s, string &oldVal, string &newVal) {
    auto pos = s.find(oldVal);
    while (pos != string::npos) {
        s.replace(pos, oldVal.size(), newVal);
        pos = s.find(oldVal, pos + newVal.size());
    }

}
int main() {
    string s = "thobbthocc";
    string oldVal = "tho";
    string newVal = "though";
    fun(s, oldVal, newVal);
    cout << s << endl;

    return 0;
}
