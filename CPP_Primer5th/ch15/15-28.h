#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class Quote {

public:
    Quote() = default;
    Quote(const Quote &q) = default;
    Quote(Quote && q) = default;;
    Quote& operator=(const Quote &q) = default;
    Quote& operator=(Quote &&q) = default;
    virtual ~Quote() = default;

    Quote(const string &s, double p): bookNo(s), price(p) {}

    string isbn() const {return bookNo;}

    virtual double net_price(size_t n) const {return n * price;}
    virtual void debug() const;

private:
    string bookNo;

protected:
    double price = 0.0;

};

void Quote::debug() const {
    cout << "Debug: " << endl;
    cout << "bookNo: " << bookNo << "\t"  << "price: " << price << endl;
}

///////////////////////////////////////
//        abstract bas      //////////
/////////////////////////////////////

class Disc_quote: public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const string &s, double p, size_t n, double dis): Quote(s, p), quantity(n), discount(dis) {}

    double net_price(size_t n) const = 0;

protected:
    size_t quantity = 0;
    double discount = 0.0;
};


///////////////////

class Bulk_quote: public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const Bulk_quote &b) = default;
    Bulk_quote(Bulk_quote &&b)= default;
    Bulk_quote& operator=(const Bulk_quote &b) = default;
    Bulk_quote& operator=(Bulk_quote &&b) = default;
    ~Bulk_quote() = default;

    //Bulk_quote(const string &s, double p, size_t n, double dis): Disc_quote(s, p, n, dis) {}
    using Disc_quote::Disc_quote;

    double net_price(size_t n) const override;
    void debug() const override;

private:
};

double Bulk_quote::net_price(size_t n) const {
    if (n > quantity) {
        return n * price * (1 - discount);
    } else {
        return n * price;
    }
}
void Bulk_quote::debug() const {
    Quote::debug();
    cout << "quantity: " << quantity << "\t" << "discount: " << discount << endl;
}

////////////////

class Limited_quote: public Disc_quote {
public:
    Limited_quote() = default;
    Limited_quote(const string &s, double p, size_t n, double dis): Disc_quote(s, p, n, dis) {}

    double net_price(size_t n) const override;
};
double Limited_quote::net_price(size_t n) const {
    if (n <= quantity) {
        return n * price * (1 - discount);
    } else {
        return (n - quantity) * price + n * price * (1 - discount);
    }
}

///////////  dynamic bind /////////////
double print_total(ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
        << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

