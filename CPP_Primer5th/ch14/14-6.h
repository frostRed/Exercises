#include <iostream>
#include <string>
using std::string;
using std::istream;
using std::ostream;

class Sales_data {
    friend Sales_data operator+(const Sales_data &item1, const Sales_data &item2);
    friend ostream& operator<<(ostream &os, const Sales_data &item);
    friend istream& operator>>(istream &, Sales_data &);
public:
    Sales_data(const string &str, unsigned n, double p): bookNo(str), units_sold(n), revenue(n*p) {}

    Sales_data(): Sales_data("", 0, 0) {}
    Sales_data(const string &str): Sales_data(str, 0, 0) {}
    Sales_data(istream &is): Sales_data() {is >> *this;}

    inline Sales_data operator+=(const Sales_data &rhs);

    string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data& item) {
        units_sold += item.units_sold;
        revenue += item.revenue;
        return *this;
    }
private:
    inline double avg_price() const {
        if (units_sold) {
            return revenue / units_sold;
        }
        else {
            return 0;
        }
    }
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;

};

Sales_data operator+(const Sales_data &item1, const Sales_data &item2);
ostream& operator<<(ostream &os, const Sales_data &item);
istream& operator>>(istream &, Sales_data &);

Sales_data operator+(const Sales_data &item1, const Sales_data &item2) {
    Sales_data sum = item1;
    sum.units_sold += item2.units_sold;
    sum.revenue += item2.revenue;
    return sum;
}

ostream& operator<<(ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

istream& operator>>(istream &is , Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}
Sales_data Sales_data::operator+=(const Sales_data &rhs) {
    return *this + rhs;
}
