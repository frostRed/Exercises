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
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    int grade = 0;
    cin >> grade;
    string lettergrade;
    if (grade < 60)
        lettergrade = scores[0];
    else {
        lettergrade = scores[grade / 10 - 5];
        if (grade % 10 > 7)
            lettergrade += "+";
        else if (grade % 10 < 3 && grade != 100)
            lettergrade += "-";
    }
    cout << lettergrade << endl;
 
    return 0;
}
