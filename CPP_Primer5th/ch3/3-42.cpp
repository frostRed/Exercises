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
    vector<int> vi{1, 2, 3};
    int iarr[512];

    for (decltype(vi.size()) i = 0; i < vi.size(); i++)
        iarr[i] = vi[i];
 
    return 0;
}
