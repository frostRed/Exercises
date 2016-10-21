//
// Created by paysonl on 16-10-21.
//

#include "Stack_list.h"

#include <cassert>

#include <string>
using std::string;

#include <sstream>
using std::istringstream;

#include <vector>
using std::vector;

double postfixExpr(const vector<string>& words);
vector<string> split(const string& line, const string& tag = " ");
double cal(double d1, double d2, const string& sym);

int main(int argc, char** argv) {
    //string expr(argv[1]);
    double eps = 0.00000000001;

    // at the front and end of symbols, there must be a blank space
    string expr{"4.99 1.06 * 5.9 + 6.99 1.06 * +"};
    string expr2{"6 5 2 3 + 8 * + 3 + *"};
    vector<string> words = split(expr, " ");
    vector<string> words2 = split(expr2, " ");
    assert(postfixExpr(words) - 18.69 < eps);
    assert(postfixExpr(words2) - 288 < eps);

}

vector<string> split(const string& line, const string& tag) {
    vector<string> words;
    istringstream in(line);
    string word;
    while (in >> word)
        words.push_back(word);

    return words;
}

double cal(double d1, double d2, const string& sym) {
    if (sym == "+")
        return d1 + d2;
    if (sym == "-")
        return d1 - d2;
    if (sym == "*")
        return d1 * d2;
    if (sym == "/")
        return d1 / d2;
}
double postfixExpr(const vector<string>& words) {
    string nums{"0123456789"};
    Stack<double> stack;
    for (auto &i: words) {
        if (i.find_first_of(nums) == string::npos) {
            double val = cal(stack.pop(), stack.pop(), i);
            stack.push(val);
        }
        else
            stack.push(std::stod(i));
    }
    return stack.pop();
}
