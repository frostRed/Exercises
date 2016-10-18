#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    vector<unsigned> scores(11, 0);
    auto modify = scores.begin();

    unsigned grade;
    while (cin >> grade)
        if (grade <= 100)
            (*(modify + grade / 10))++;


    for (auto i = scores.cbegin(); i != scores.cend(); ++i)
        cout << *i << endl;
 
    return 0;
}
