//
// Created by paysonl on 16-10-21.
//

#include <string>
using std::string;

#include <cassert>

#include "Stack_list.h"

bool balancingSym(const string& syms);
bool same_if(const string&s1, const string& s2);

int main(int argc, char** argv) {
    //string syms(argv[1]);
    string syms1{"[()]"};
    string syms2{"[(])"};

    assert(balancingSym(syms1));
    assert(!balancingSym(syms2));
}


bool balancingSym(const string& syms) {
    Stack<string> stac;
    for (auto i = 0; i != syms.size(); ++i) {
        string sub = syms.substr(i, 1);
        if (sub == "{" || sub == "[" || sub == "(")
            stac.push(sub);
        else if (sub == "}" || sub == "]" || sub == ")")
            if (stac.empty())
                return false;
            else if (!same_if(stac.top(), sub))
                return false;
            else
                stac.pop();
    }
    if (!stac.empty())
        return false;
    return true;
}

bool same_if(const string&s1, const string& s2) {
    if ( (s1 == "{" && s2 == "}") ||
            (s1 == "[" && s2 == "]") ||
            (s1 == "(" && s2 == ")") )
        return true;
    return false;
}
