#include "7-12.h"
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

int main() {
    Sales_data total(cin);
    if (!total.isbn().empty()) {
        Sales_data trans;
        while (read(cin, trans)) {
            if (total.isbn() == trans.isbn()) {
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
    return 0;
}
