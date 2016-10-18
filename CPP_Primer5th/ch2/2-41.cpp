#include <iostream>
#include <string>
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
void f1_20();
void f1_21();

int main() {
    f1_20();
    f1_21();

    return 0;
}

void f1_20() {
    Sales_data item;
    double price = 0.0;
    while (std::cin >> item.bookNo >> item.units_sold >> price) {
        item.revenue = item.units_sold * price;
        std::cout << item.bookNo << item.units_sold << item.revenue << std::endl;
    }
}

void f1_21() {
    Sales_data item1, item2;
    double price = 0.0;
    std::cin >> item1.bookNo >> item1.units_sold >> price;
    item1.revenue = item1.units_sold * price;
    std::cin >> item2.bookNo >> item2.units_sold >> price;
    item2.revenue = item2.units_sold * price;
    if (item1.bookNo == item2.bookNo) {
        unsigned totalCnt = item1.units_sold + item2.units_sold;
        double totalRevenue = item1.revenue + item2.revenue;
        std::cout << item1.bookNo << " " << totalCnt << " "  << totalRevenue;
        
        if (totalCnt != 0)
            std::cout << totalRevenue / totalCnt << std::endl;
        else
            std::cout << "(no sales)" << std::endl;
    }
    else {
        std::cerr << "Data must refer to the same ISBN" << std::endl;
    }
}
