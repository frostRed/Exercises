#include <iostream>
#include <string>
using std::string;
using std::istream;

class Tree {
public:
    Tree(const string & kd, const string &co, double ht): kind(kd), color(co), height(ht) {}
    Tree() = default;
    Tree(istream &is);

private:
    string kind = "null";
    string color = "null";
    double height = 0;
};
