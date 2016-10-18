#include <string>
#include <iostream>
using std::string;

void fun1(string &s) {
    string nums("0123456789");
    string alp("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    string::size_type pos = 0;
    while ((pos = s.find_first_of(nums, pos)) != string::npos) {
        std::cout << s[pos] << std::endl;
        ++pos;
    }
    pos = 0;
    while ((pos = s.find_first_of(alp, pos)) != string::npos) {
        std::cout << s[pos] << std::endl;
        ++pos;
    }
}
void fun2(string &s) {
    string nums("0123456789");
    string alp("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    string::size_type pos = 0;
    while ((pos = s.find_first_not_of(alp, pos)) != string::npos) {
        std::cout << s[pos] << std::endl;
        ++pos;
    }
    pos = 0;
    while ((pos = s.find_first_not_of(nums, pos)) != string::npos) {
        std::cout << s[pos] << std::endl;
        ++pos;
    }
}

int main() {
    string s("ab2c3d7R4E6");
    fun1(s);
    fun2(s);

    return 0;
}
