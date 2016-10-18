#include "15-28.h"
#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;
using std::make_shared;

int main() {
    vector<shared_ptr<Quote>> v;
    v.push_back(make_shared<Bulk_quote>("xyz", 40.0, 5, 0.8));
    v.push_back(make_shared<Bulk_quote>("abc", 50.0, 10, 0.8));

    vector<size_t> size{10, 20};
    double sum = 0;
    for (size_t i = 0; i != size.size(); ++i) {
        sum += v[i]->net_price(size[i]);
    }
    cout << sum << endl;

    return 0;
}
