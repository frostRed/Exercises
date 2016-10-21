//
// Created by paysonl on 16-10-21.
//

#include "Stack_list.h"

#include <cassert>

#include <string>
using std::string;

#include <sstream>
using std::istringstream;
using std::ostringstream;


#include <vector>
using std::vector;

vector<string> split(const string& line, const string& tag);
bool is_Syms(const string& s);
string infix2postfix(const vector<string>& words);

int main(int argc, char** argv) {
    //string postfix{argv[1]};

    // at the front and end of symbols, there must be a blank space
    string posfix{"a + b * c + ( d * e + f ) * g"};
    vector<string> words = split(posfix, " ");
    assert(infix2postfix(words) == "a b c * + d e * f + g * +");
}

vector<string> split(const string& line, const string& tag) {
    vector<string> words;
    istringstream in(line);
    string word;
    while (in >> word)
        words.push_back(word);

    return words;
}

bool is_Syms(const string& s) {
    // these symbols need push to stack
    if (s == "+" || s == "-" || s == "*" || s == "/" || s == "(" || s == ")")
        return true;
    return false;
}
string infix2postfix(const vector<string>& words) {
    ostringstream out;
    Stack<string> stack;
    for (auto &i: words) {
        if (!is_Syms(i))
            // i not be + - * / ( )
            out << i << " ";
        else if (i == "(")
            stack.push(i);
        else if (i == ")") {
            while (stack.top() != "(")
                out << stack.pop() << " ";
            // remeber pop the (, but not output
            stack.pop();
        }
        else if (i == "*" || i == "/") {
            // if stack.top() is not +  - (, should pop() and output
            while (stack.top().find_first_of("+-(") == string::npos &&
                    !stack.empty())
                out << stack.pop() << " ";
            stack.push(i);
        }
        else if (i == "+" || i == "-") {
            while (stack.top() != "(" && !stack.empty())
                out << stack.pop() << " ";
            stack.push(i);
        }
    }

    while (!stack.empty())
        out << stack.pop() << " ";

    // delete the last blank space
    return out.str().substr(0, out.str().size() - 1);
}
