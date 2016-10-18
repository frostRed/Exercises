#include <memory>

int main() {
    std::unique_ptr<int> up(new int(42));

    //std::unique_ptr<int> up2(up);

    std::unique_ptr<int> up3;
    up3 = up;
    return 0;
}
