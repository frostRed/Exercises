//
// Created by paysonl on 16-10-19.
//

long long pow(long long x, int n) {
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;

    if (n % 2)
        return x * pow(x * x, n / 2);
    else (n % 2 == 0)
        return pow(x * x, n / 2);
}
