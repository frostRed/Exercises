#include <tuple>
using std::tuple;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
#include <iterator>

#include "Sales_data.h"

using shop_recoder = vector<Sales_data>;
using match = tuple<shop_recoder::size_type, shop_recoder::const_iterator, shop_recoder::const_iterator>;

vector<match> find_book(const vector<shop_recoder> &files, const string &book) {
    vector<match> ret;
    for (auto &shop: files) {
        auto ite_pair = equal_range(shop.cbegin(), shop.cend(), book,
                [](const Sales_data &sd1, const Sales_data &sd2) { return sd1.isbn() < sd2.isbn(); });
        if (ite_pair.first != ite_pair.second) {
            ret.push_back(match(ite_pair.first - ite_pair.first,
                        ite_pair.first,
                        ite_pair.second));
        }
    }
    return ret;
}
