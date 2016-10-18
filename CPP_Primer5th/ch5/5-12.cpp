#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
    unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;

    char ch;
    bool flag = false;
    while (cin >> ch) {
        if (!flag && ch == 'f') {
            flag = true;
            continue;
        }
        if (flag) {
            switch (ch) {
                case 'f':
                    ++ffCnt;
                    flag = false;
                    break;
                case 'l':
                    ++flCnt;
                    flag = false;
                    break;
                case 'i':
                    ++fiCnt;
                    flag = false;
                    break;
                default:
                    flag = false;
                    break;
            }
        }
    }
    cout << "Number of ff: \t" << ffCnt  << '\n'
        << "Number of fl: \t" << flCnt << '\n'
        << "Number of fi:\t" << fiCnt << endl;

    return 0;
}
