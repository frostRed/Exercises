#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
struct Sales_data {
public:
    Sales_data() = default;
    Sales_data(std::string &s, unsigned u, double d): bookNo(s), units_sold(u), revenue(u) {}

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
#endif
