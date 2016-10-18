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

bool f(vector<int> &iv1, vector<int> &iv2) {
    vector<int> &iv_short = iv1.size() <= iv2.size() ? iv1 : iv2;
    vector<int> &iv_long = iv1.size() <= iv2.size() ? iv2 : iv1;

    auto size = iv_short.size();
    decltype(size) index = 0;
    for ( ; index != size; ++index) {
        if (iv_short[index] != iv_long[index]) {
            return false;
        }
    }
    return true;

}
int main() {
    vector<int> iv1{0, 1, 1, 2, 3, 5, 8};
    vector<int> iv2{0, 1, 1, 2};
 
    cout << f(iv1, iv2) << endl;
    return 0;
}
