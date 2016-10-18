#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class Quote {

public:
    Quote(): bookNo("") { cout << "Quote()" << endl; };
    Quote(const Quote &q): bookNo(q.bookNo) { cout << "Quote(const Quote &)" << endl; };
    Quote(Quote && q): bookNo(std::move(q.bookNo)) { cout << "Quote(const Quote &&)" << endl; };
    Quote& operator=(const Quote &q) {
        bookNo = q.bookNo;
        cout << "operator=(const Quote &)" << endl;
        return *this;
    };
    Quote& operator=(Quote &&q) {
        bookNo = std::move(q.bookNo);
        cout << "operator(Quote &&)" << endl;
        return *this;
    }
    virtual ~Quote() { cout << "~Quote()" << endl; };

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
    Bulk_quote(): Disc_quote() { cout << "Bulk_quote()" << endl; }
    Bulk_quote(const Bulk_quote &b): Disc_quote(b) { cout << "Bulk_quote(const Bulk_quote &)" << endl; };
    Bulk_quote(Bulk_quote &&b): Disc_quote(std::move(b)) { cout << "Bulk_quote(const Bulk_quote &&)" << endl; };
    Bulk_quote& operator=(const Bulk_quote &b) {
        Disc_quote::operator=(b);
        cout << "operator=(const Bulk_quote &)" << endl; 
        return *this;
    };
    Bulk_quote& operator=(Bulk_quote &&b) {
        Disc_quote::operator=(std::move(b));
        cout << "operator=(const Bulk_quote &&)" << endl; 
        return *this;
    }
    ~Bulk_quote() { cout << "~Bulk_quote()" << endl; }

    Bulk_quote(const string &s, double p, size_t n, double dis): Disc_quote(s, p, n, dis) {}

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

