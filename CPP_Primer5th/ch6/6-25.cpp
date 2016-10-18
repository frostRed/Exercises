#include <string>
#include <iostream>
using std::string;

int main(int argc, char *argv[]) {
    string s;
    s = s + argv[1] + argv[2];
    std::cout << s << std::endl;
    return 0;
}
