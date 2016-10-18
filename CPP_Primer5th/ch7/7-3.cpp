#include <iostream>
#include "7-2.h"
using std::cout;
using std::cin;
using std::endl;
using std::cerr;


int main() {
    Sales_data total, trans;
    double price = 0.0;

    if (cin >> total.bookNo >> total.units_sold >> price) {
        total.revenue = total.units_sold * price;
        while (cin >> trans.bookNo >> trans.units_sold >> price) {
            trans.revenue = trans.units_sold * price;
            if (trans.isbn() == total.isbn()) {
                total.combine(trans);
            }
            else {
                cout << total.isbn() << " " << total.units_sold << total.revenue << total.revenue / total.units_sold << endl;
                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
            }
        }
        cout << total.isbn() << " " << total.units_sold << total.revenue << total.revenue / total.units_sold << endl;

    }
    else {
        cerr << "No data?!" << endl;
    }

}
