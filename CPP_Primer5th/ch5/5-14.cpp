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
    vector<string> strVec;
    string strMax, str1, str2;
    unsigned cntMax = 1, cntCurr = 1;

    while (cin >> str1) {
        while (cin >> str2) {
            if (str2 == str1) {
                ++cntCurr;
                if (cntCurr > cntMax) {
                    cntMax = cntCurr;
                    strMax = str2;
                }
            }
            else {
                str1 = str2;
                cntCurr = 1;
            }
        }
    }

    if (cntMax == 1) {
        cout << "No word continues" << endl;
    }
    else {
        cout << strMax << " " << cntMax << " times" << endl;
    }

 
    return 0;
}
