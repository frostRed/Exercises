#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include "Sales_data.h"
using std::vector;
using std::ifstream;
using std::istringstream;
using std::ostream_iterator;
using std::istream_iterator;

ifstream &readFile(ifstream &fin, const string &fname, vector<Sales_data> &v_sd) {
    fin.open(fname);
    if (fin) {
        Sales_data tmp;
        string line;
        while (getline(fin, line)) {
            istringstream sin(line);
            read(sin, tmp);
            v_sd.push_back(tmp);
        }
    }
    fin.close();
    return fin;
}
bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2) {
    return sd1.isbn().size() < sd2.isbn().size();
}

int main(int agrc, char *argv[]) {
    ifstream fin;
    vector<Sales_data> sd_v;
    readFile(fin, argv[1], sd_v);
    
    sort(sd_v.begin(), sd_v.end(), compareIsbn);

    auto beg = sd_v.begin();
    while (beg != sd_v.end()) {
        auto end = find_if(beg, sd_v.end(), [&beg](const Sales_data &item) {return item.isbn() != beg->isbn();});
        auto sum = std::accumulate(beg, end, Sales_data(beg->isbn()));
        ostream_iterator<Sales_data> out_ite(std::cout, "\n");
        out_ite = sum;
        beg = end;
    }

    return 0;
}
