#include <iostream>
#include <string>
using std::string;
using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

struct Sales_data {
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;

    Sales_data() = default;
    Sales_data(const string &str): bookNo(str) {}
    Sales_data(const string &str, unsigned n, double p): bookNo(str), units_sold(n), revenue(n*p) {}
    Sales_data(istream &is);


    string isbn() const {
        return bookNo;
    }

    Sales_data& combine(const Sales_data& item) {
        units_sold += item.units_sold;
        revenue += item.revenue;
        return *this;
    }
    double avg_price() const {
        if (units_sold) {
            return revenue / units_sold;
        }
        else {
            return 0;
        }
    }
};
istream &read(istream &is, Sales_data &item);
ostream &print(ostream &os, const Sales_data &item);

Sales_data::Sales_data(istream &is) {
    read(is, *this);
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

int main() {
    Sales_data item1("string");
    Sales_data item2("vector", 5, 2.48);

    Sales_data item3(cin);


    print(cout, item1) << endl;
    print(cout, item2) << endl;
    print(cout, item3) << endl;
    return 0;
}
