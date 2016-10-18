#include <iostream>
#include <string>
using std::string;
using std::istream;
using std::ostream;


struct Person {
    string name;
    string address;
    string nam() const {return name;}
    string adde() const {return address;}
    
    istream &read(istream &is, Person &p);
    ostream &print(ostream &os, const Person &p);
};
istream &Person::read(istream &is, Person &p) {
    is >> p.name >> p.address;
    return is;
}
ostream &Person::print(ostream &os, const Person &p) {
    os << p.nam() << p.adde();
    return os;
}
