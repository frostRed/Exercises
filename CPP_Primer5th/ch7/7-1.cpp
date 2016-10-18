#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main() {
    Sales_data total, trans;
    double price = 0.0;

    if (cin >> total.bookNo >> total.units_sold >> price) {
        total.revenue = total.units_sold * price;
        while (cin >> trans.bookNo >> trans.units_sold >> price) {
            trans.revenue = trans.units_sold * price;
            if (trans.bookNo == total.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }
            else {
                cout << total.bookNo << " " << total.units_sold << total.revenue << total.revenue / total.units_sold << endl;
                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
            }
        }
        cout << total.bookNo << " " << total.units_sold << total.revenue << total.revenue / total.units_sold << endl;

    }
    else {
        cerr << "No data?!" << endl;
    }

}
