#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int []> up(new int[10]);
    up.release();

    return 0;
}
