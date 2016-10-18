#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class Quote {

public:
    Quote() = default;
    Quote(const string &s, double p): bookNo(s), price(p) {}

    string isbn() const {return bookNo;}

    virtual double net_price(size_t n) const {return n * price;}
    virtual ~Quote() = default;

private:
    string bookNo;


protected:
    double price = 0.0;

};

double print_total(ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
        << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}
