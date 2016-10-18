#include "15-26.h"

int main() {
    Quote q1;
    Quote q2("xyz", 30);
    cout << "---------------------" << endl;
    Quote q3(q2);
    q3 = q1;
    cout << "---------------------" << endl;
    Quote q4 = std::move(q3);
    q1 = std::move(q2);
    cout << "---------------------" << endl;

    Bulk_quote b1;
    Bulk_quote b2("edf", 20, 25, 0.7);
    cout << "---------------------" << endl;
    Bulk_quote b3(b1);
    b3 = b2;
    cout << "---------------------" << endl;
    Bulk_quote b4 = std::move(b1);
    b3 = std::move(b4);
    cout << "---------------------" << endl;
    

}
