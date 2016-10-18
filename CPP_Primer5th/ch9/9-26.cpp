#include <vector>
#include <list>
#include <iterator>

int main() {
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    std::vector<int> iv(std::begin(ia), std::end(ia));
    std::list<int> il(std::begin(ia), std::end(ia));

    auto iv_beg = iv.begin();
    while (iv_beg != iv.end()) {
        if (*iv_beg % 2 == 0) {
            iv_beg = iv.erase(iv_beg);
        }
    }
    auto il_beg = il.begin();
    while (il_beg != il.end()) {
        if (*il_beg % 2) {
            il_beg = il.erase(il_beg);
        }
    }

    return 0;
}
