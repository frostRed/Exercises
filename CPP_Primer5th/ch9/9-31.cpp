#include <iostream>
#include <list>
#include <forward_list>

int main() {
    std::list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = li.begin();
    while (iter != li.end()) {
        if (*iter % 2) {
            iter = li.insert(iter, *iter);
            ++iter;
            ++iter;
        } else {
            iter = li.erase(iter);
        }
    }

    std::forward_list<int> fli = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto pre = fli.before_begin();
    auto iter2 = fli.begin();
    while (iter2 != fli.end()) {
        if (*iter2 % 2) {
            pre = fli.insert_after(pre, *iter2);
            ++pre;
            iter2 = pre;
            ++iter2;
        } else {
            iter2 = fli.erase_after(pre);
        }
    }

    for (auto i: fli) {
        std::cout << i << std::endl;
    }
    return 0;
}
