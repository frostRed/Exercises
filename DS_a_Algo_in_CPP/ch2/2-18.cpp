//
// Created by paysonl on 16-10-20.
//

#include <cassert>
#include <vector>
using std::vector;

#include <iostream>

#include <functional>
using std::bind;
using std::placeholders::_1;

template <typename Fun>
double find_zero(const Fun& f, double low, double high, double eps = 0.001);

double polynomial(const vector<double>& a, double x);

int main() {
    vector<double> a{3, -3.5, 1};
    double eps = 0.00000000001;
    auto f = bind(polynomial, a, _1);

    assert(find_zero(f, 0, 1.6) == 1.5);
    assert(find_zero(f, 1.6, 2.6) - 2 <= eps);

    assert(find_zero([&a](double x) {return polynomial(a, x);}
            , 0, 1.6, eps) == 1.5);

}

double polynomial(const vector<double>& a, double x) {
    double poly = 0;
    int n  = a.size() - 1;
    for (int i = n; i >= 0; --i)
        poly = x * poly + a[i];
    return poly;
}

template <typename Fun>
double find_zero(const Fun& f, double low, double high, double eps) {
    double mid = (low + high) / 2;
    if (f(mid) <= eps && f(mid) >= -eps)
        return mid;

    if (f(mid) * f(low) > 0)
        return find_zero(f, mid, high, eps);
    else if (f(mid) * f(high) > 0)
        return find_zero(f, low, mid, eps);

}
