#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

void fun(string &s, string &oldVal, string &newVal) {
    auto pos = s.find(oldVal);
    while (pos != string::npos) {
        auto beg = s.begin();
        // 到待插入的位置
        beg += pos;
        s.insert(beg, newVal.begin(), newVal.end());
        // 重新定位
        beg = s.begin();
        beg += pos;
        s.erase(beg + newVal.size(), beg + newVal.size() + oldVal.size());
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
