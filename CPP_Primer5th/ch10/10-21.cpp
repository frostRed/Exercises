#include <iostream>

int main() {
    int val = 3;
    auto f = [=]() mutable ->bool {if (val - 1 != 0) {
                                        --val;
                                        return false;
                                    }
                                    else {
                                        return true;
                                        }
                                    };

    f();
    f();
    std::cout << f() << std::endl;
    return 0;
}
