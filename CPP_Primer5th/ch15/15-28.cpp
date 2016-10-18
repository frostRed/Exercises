#include "15-28.h"
#include <vector>

using std::vector;

int main() {
    vector<Quote> v;
    v.push_back(Bulk_quote("xyz", 40.0, 5, 0.8));
    v.push_back(Bulk_quote("abc", 50.0, 10, 0.8));

    vector<size_t> size{10, 20};
    double sum = 0;
    for (size_t i = 0; i != size.size(); ++i) {
        sum += v[i].net_price(size[i]);
    }
    cout << sum << endl;

    return 0;
}
