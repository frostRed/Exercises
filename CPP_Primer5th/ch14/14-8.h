#include <iostream>
#include <string>
using std::string;
using std::istream;
using std::ostream;

class Tree {
    friend ostream& operator<<(ostream &, const Tree &);
    friend istream& operator>>(istream &, Tree &);
public:
    Tree(const string & kd, const string &co, double ht): kind(kd), color(co), height(ht) {}
    Tree(): Tree("null", "null", 0) {}
    Tree(istream &is);

private:
    string kind = "null";
    string color = "null";
    double height = 0;
};

ostream& operator<<(ostream &out, const Tree &t) {
    out << t.kind << "\t" << t.color << "\t" << t.height;
    return out;
}
istream& operator>>(istream &in, Tree &t) {
    in >> t.kind >> t.color >> t.height;
    return in;
}
