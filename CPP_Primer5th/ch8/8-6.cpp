#include <iostream>
#include <fstream>
#include "Sales_data.h"
using std::ifstream;
using std::cout;
using std::endl;
using std::cerr;

int main(int argc, char *argv[]) {
    Sales_data total;
    ifstream ifstr(argv[1]);

    if (ifstr) {
        if (read(ifstr, total)) {
            Sales_data trans;
            while (read(ifstr, trans)) {
                if (total.isbn() == trans.isbn()) {
                    total.combine(trans);
                } else {
                    print(cout, total) << endl;
                    total = trans;
                }
            }
            print(cout, total) << endl;
        } else {
            cerr << "No data?!" << endl;
        }

    }
    return 0;
}


