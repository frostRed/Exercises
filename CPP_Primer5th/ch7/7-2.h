#include <string>
using std::string;

struct Sales_data {
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;

    string isbn() const {
        return bookNo;
    }

    Sales_data& combine(const Sales_data& item) {
        units_sold += item.units_sold;
        revenue += item.revenue;
        return *this;
    }
};
