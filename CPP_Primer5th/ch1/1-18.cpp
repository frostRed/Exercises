#include <iostream>

int main() {
    int val = 0, currVal = 0;

    if (std::cin >> currVal) {
        int cnt = 1;
        while (std::cin >> val) {
            if (currVal == val) {
                ++cnt;
            }
            else {
                std::cout << currVal << " occurs " << cnt << " times" << std::endl;
                cnt = 1;
                currVal = val;
            }
        }
        std::cout << currVal << " occurs " << cnt << " times" << std::endl;
    }
}