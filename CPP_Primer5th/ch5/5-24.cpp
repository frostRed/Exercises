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
    cin >> i >> j;
    try {
        if (!j) {
            throw runtime_error("divided number is zero!");
        }
        cout << i / j << endl;
    } catch (runtime_error err) {

    }

    return 0;
}
