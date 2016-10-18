#include <iostream>
using std::cout;
using std::endl;
#include <regex>
using std::regex;
using std::smatch;
#include <string>
using std::string;
#include <exception>
using std::regex_error;

int main() {
    string p1("[^cei");

    try {
        regex r1(p1);
        smatch s1;
        string test("receipt friend theif receive");
        if (regex_search(test, s1, r1)) {
            cout << s1.str() << endl;
        }
    }
    catch (regex_error e) {
        cout << e.what() << "\ncode: " << e.code() << endl;
    }

}
