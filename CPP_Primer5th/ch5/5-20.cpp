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
    string strCurr, strSave;
    bool flag = false;
    while (cin >> strCurr) {
        if (strCurr != strSave) {
            strSave = strCurr;
        }
        else {
            cout << strCurr << endl;
            flag = true;
            break;
        }
    }
    if (!flag)
        cout << "no word continues" << endl;
 
    return 0;
}
