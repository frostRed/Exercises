#include <string>
#include <iostream>
using std::string;
using std::istream;

class ReadString {
public:
    ReadString(istream &i, const string &s = ""): in(i), line(s) {}

    string operator()() {
        getline(in, line);
        if (in) {
            return line;
        } else {
            return "";
        }
    }

private:
    istream &in;
    string line;

};
