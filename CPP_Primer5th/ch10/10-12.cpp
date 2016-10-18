#include<vector>
#include <iostream>
#include <algorithm>
#include "Sales_data.h"

bool compareIsbn(Sales_data &sd1, Sales_data &sd2) {
    return sd1.isbn() < sd2.isbn();
}

int main() {
    std::vector<Sales_data> sd_vec = {{"bcd", 20, 3.5},
                                    {"acef", 10, 5.6},
                                    {"fjeo", 8, 5.9}};

    sort(sd_vec.begin(), sd_vec.end(), compareIsbn);
    std::cout << sd_vec[0].isbn() << std::endl;
    return 0;
}
