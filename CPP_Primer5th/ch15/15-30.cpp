#include "15-30.h"
#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;
using std::make_shared;

int main() {
    Basket b;
    Bulk_quote book1("xyz", 40.0, 3, 0.8);
    b.add_item(book1);
    b.add_item(book1);
    b.add_item(book1);
    b.total_receipt(cout);

    b.add_item(book1);
    b.total_receipt(cout);
    return 0;
}
