#include <iostream>
#include <stdexcept>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::runtime_error;
using std::string;

int main() {
    int i, j;
    cout << "Enter two numbers: " << endl;
    while (cin >> i >> j) {
        try {
            if (!j) {
                throw runtime_error("divided number is zero!");
            }
            cout << i / j << endl;
            break;
        } catch (runtime_error err) {
            cout << err.what() << endl;
            cout << "Enter yes to re-Enter two numbers, no to terminate: ";
            string rsp;
            cin >> rsp;
            if (rsp[0] == 'y') {
                cout << "Ok, re-enter two numbers: " << endl;
                continue;
            }
            else 
                break;
        }

    }

    return 0;
}
