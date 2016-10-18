#include <string>
using std::string;

struct Person {
    string name;
    string address;
    string nam() const {return name;}
    string adde() const {return address;}
};
