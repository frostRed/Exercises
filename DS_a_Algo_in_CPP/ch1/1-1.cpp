//
// Created by paysonl on 16-10-15.
//
#include <iostream>
#include <vector>
using std::vector;

#include <string>
#include <random>
using std::default_random_engine;
using std::uniform_real_distribution;

#include <algorithm>
#include <cassert>

#include <fstream>
using std::ofstream;

#include <chrono>
using std::chrono::system_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;

vector<double> randN(int n);
double run(const vector<double>& vd);

template <typename Compare>
void sort(vector<Compare>& v);

int main(int argc, char** argv) {
    // N is vector size
    // M is the times to increase vector size
    int sz = std::stoi(argv[1]);
    int M = std::stoi(argv[2]);

    ofstream out("time", ofstream::out);

    for (int i = 0; i != M; ++i) {
        sz *= 2;
        vector<double> vd = randN(sz);
        auto start = system_clock::now();
        double result = run(vd);
        auto end = system_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        auto t = double(duration.count()) * microseconds::period::num / microseconds::period::den;
        out << t << std::endl;
    }


    return 0;
}

vector<double> randN(int n) {
    static default_random_engine e;
    static uniform_real_distribution<double> u(0, 9);
    vector<double> vd;
    for (int i = 0; i != n; ++i)
        vd.push_back(u(e));
    return vd;
}

double run(const vector<double>& vd) {
    auto N = vd.size();
    auto k = vd.size() / 2;
    vector<double> vd_k;
    for (decltype(k) i = 0; i != k; ++i)
        vd_k.push_back(vd[i]);

    std::sort(vd_k.begin(), vd_k.end(), [](double a, double b) { return a > b;});
    for (auto i = k; i != N; ++i) {
        if (vd[i] > vd_k[k]) {
            vd_k[k] = vd[i];
            for (auto j = k; j >= 1; --j) {
                    auto tmp = vd_k[j - 1];
                    if (vd_k[j] > vd_k[j - 1]) {
                        vd_k[j - 1] = vd_k[j];
                        vd_k[j] = tmp;
                    }
            }
        }
    }
    return *(vd_k.cend() - 1);


}

template <typename Compare>
void sort(vector<Compare>& v, unsigned long lo, unsigned long hi);

// Quick sort, but is less to greater
template <typename Compare>
void sort(vector<Compare>& v) {
    sort(v, 0, v.size() - 1);

}

template <typename Compare>
unsigned long partition(vector<Compare>& v, unsigned long lo, unsigned long hi);

template <typename Compare>
void sort(vector<Compare>& v, unsigned long  lo, unsigned long hi) {
    if (hi <= lo) return;
    auto j = partition(v, lo, hi);
    sort(v, 0, lo);
    sort(v, lo + 1, hi);
}

template <typename Compare>
unsigned long partition(vector<Compare>& v, unsigned long lo, unsigned long hi) {
    auto i = lo, j = hi + 1;
    Compare obj = v[lo];
    while (true) {
        while (v[++i] < obj)
            if (i == hi)
                break;
        while (obj < v[--j])
            if (j == lo)
                break;
        if (i >= j)
            break;
        std::swap(v[i], v[j]);
    }
    std::swap(v[lo], v[j]);
    return j;
}
