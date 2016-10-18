#include <iostream>
#include <string>
using std::string;
using std::istream;
using std::ostream;

class Sales_data {
    friend istream &read(istream &is, Sales_data &item);
    friend Salse_data add(const Sales_data &item1, const Sales_data & item2);
    friend ostream &print(ostream &os, const Sales_data &item);
public:
    Sales_data() = default;
    Sales_data(const string &str): bookNo(str) {}
    Sales_data(const string &str, unsigned n, double p): bookNo(str), units_sold(n), revenue(n*p) {}
    Sales_data(istream &is) {
        read(is, *this);
    }

    string isbn() const {
        return bookNo;
    }
    Sales_data& combine(const Sales_data& item) {
        units_sold += item.units_sold;
        revenue += item.revenue;
        return *this;
    }
private:
    double avg_price() const {
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
Salse_data add(const Sales_data &item1, const Sales_data & item2);
istream &read(istream &is, Sales_data &item);
ostream &print(ostream &os, const Sales_data &item);

Salse_data add(const Sales_data &item1, const Sales_data & item2) {
    Sales_data sum = item1;
    sum.combine(item2);
    return sum;
}

istream &read(istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

ostream &print(ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

