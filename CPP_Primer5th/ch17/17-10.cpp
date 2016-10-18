#include <vector>
using std::vector;
#include <bitset>
using std::bitset;

int main() {
    vector<int> vi{1, 2, 3, 5, 8, 13, 21};
    bitset<24> b1("1000000010000100101110");
    bitset<24> b2(b1);
    bitset<24> b3;
    for (auto i: vi) b3.set(i);
}
