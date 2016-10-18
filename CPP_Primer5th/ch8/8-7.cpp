#include <iostream>
#include <fstream>
#include "Sales_data.h"
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::cerr;

int main(int argc, char *argv[]) {
    Sales_data total;
    ifstream ifstr(argv[1]);
    ofstream ofstr(argv[2]);

    if (ifstr && ofstr) {
        if (read(ifstr, total)) {
            Sales_data trans;
            while (read(ifstr, trans)) {
                if (total.isbn() == trans.isbn()) {
                    total.combine(trans);
                } else {
                    print(ofstr, total) << endl;
                    total = trans;
                }
            }
            print(ofstr, total) << endl;
        } else {
            cerr << "No data?!" << endl;
        }

    }
    return 0;
}


