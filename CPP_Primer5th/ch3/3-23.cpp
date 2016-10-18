#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    vector<int> vi(10, 2);
    for (auto vi_ite = vi.begin(); vi_ite != vi.end(); ++vi_ite) {
        *vi_ite = *vi_ite * 2;
        cout << *vi_ite << endl;
    }
 
    return 0;
}
