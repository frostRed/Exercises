//
// Created by paysonl on 16-10-19.
//

long long gcd(long long m, long long n) {
    while (n != 0) {
        long long r = m % n;
        m = n;
        n = r;
    }
    return m;
}
