#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;

int main() {
    int grade = 95;
    string finalgrade;
    finalgrade = (grade > 90) ? "high pass"
                            : (grade > 75) ? "pass"
                                        : (grade > 60) ? "low pass" : "fail";

    if (grade > 90)
        finalgrade = "high pass";
    else if (grade > 75)
        finalgrade = "pass";
    else if (grade > 60)
        finalgrade = "low pass";
    else
        finalgrade = "fail";
 
    return 0;
}
