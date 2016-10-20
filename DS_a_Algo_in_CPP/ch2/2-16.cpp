//
// Created by paysonl on 16-10-20.
//
#include <cassert>

long long gcd(long long a, long long b);

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;

    if (a % 2 == 0 && b % 2 == 0)
        return 2 * gcd(a / 2, b / 2);
    else if (a % 2 == 1 && b % 2 == 1)
        return gcd((a + b) / 2, (a - b) / 2);
    else if (a % 2 == 0 && b % 2 == 1)
        return gcd(a / 2, b);
    else
        return gcd(a, b / 2);
}

int main() {
    assert(gcd(4, 2) == 2);
    assert(gcd(6, 3) == 3);
    assert(gcd(12, 3) == 3);
    assert(gcd(15, 6) == 3);

}
