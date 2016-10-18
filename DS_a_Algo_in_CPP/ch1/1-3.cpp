//
// Created by paysonl on 16-10-17.
//


#include <iostream>
using std::cout;

#include <stdexcept>
using std::out_of_range;

void run(double);
void printDigit(int);
void printDoub(double);
void printInt(int);


int main(int argc, char** argv) {
    double d = std::stod(argv[1]);
    run(d);
}

void run(double d) {
    int inte = 0;
    double deci = 0;
    if (d < 0) {
        cout << "-";
        inte = static_cast<int>(-d);
        deci = -d - inte;
    } else {
        inte = static_cast<int>(d);
        deci = d - inte;
    }
    printInt(inte);
    cout << ".";
    printDoub(deci);
}

void printDigit(int n) {
    if (n < 0 || n >= 10)
        throw out_of_range("n must be 0 <= n < 10");
    cout << n;
}

void printInt(int n) {
    if (n > 10)
        printInt(n / 10);
    printDigit(n % 10);
}

void printDoub(double d) {
    // d must be 0...
    int inte = static_cast<int>(d * 10);
    double deci = d * 10 - inte;
    printDigit(inte);
    if (deci == 0) {
        return;
    }
    else {
        printDoub(deci);
    }
}
