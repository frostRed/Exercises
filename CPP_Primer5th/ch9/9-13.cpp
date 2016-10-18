#include <list>
#include <vector>
using std::list;
using std::vector;

int main() {

    list<int> il1{1, 2, 3};
    vector<int> iv1{4, 5, 6};

    vector<double> dv(il1.begin(), il1.end());
    vector<double> dv2(iv1.begin(), iv1.end());

    return 0;
}
