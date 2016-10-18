#include <tuple>
using std::tuple;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
#include <iterator>
#include <utility>
using std::pair;

#include "Sales_data.h"

using shop_recoder = vector<Sales_data>;
using ite_pair = pair<shop_recoder::const_iterator, shop_recoder::const_iterator>;

using match = pair<shop_recoder::size_type, ite_pair>;

vector<match> find_book(const vector<shop_recoder> &files, const string &book) {
    vector<match> ret;
    for (auto &shop: files) {
        auto found = equal_range(shop.cbegin(), shop.cend(), book,
                [](const Sales_data &sd1, const Sales_data &sd2) { return sd1.isbn() < sd2.isbn(); });
        if (found.first != found.second) {
            ret.push_back(make_pair(found.first - found.first,
                        make_pair(found.first, found.second)));
        }
    }
    return ret;
}
