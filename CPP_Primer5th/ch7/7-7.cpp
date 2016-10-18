#include "7-6.h"
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main() {
    Sales_data total, trans;
    double price = 0.0;

    if (read(cin, total)) {
        while (read(cin, trans)) {
            if (trans.isbn() == total.isbn()) {
                total.combine(trans);
            }
            else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else {
        cerr << "No data?!" << endl;
    }

}
