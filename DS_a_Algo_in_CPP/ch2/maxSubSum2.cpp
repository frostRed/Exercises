//
// Created by paysonl on 16-10-18.
//
#include <cassert>

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ofstream;

#include <random>
using std::default_random_engine;
using std::uniform_int_distribution;

#include <chrono>
using std::chrono::system_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;

vector<int> randN(int n);

int maxSubSum2(const vector<int>& a) {
    int maxSum = 0;
    for (int i = 0; i != a.size(); ++i) {
        int thisSum = 0;
        for (int j = i; j < a.size(); ++j) {
            thisSum += a[j];
            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}

int main(int argc, char** argv) {
    int N = std::stoi(argv[1]);
    int M = std::stoi(argv[2]);

    ofstream out("time2", ofstream::out);

    int sz = N;
    for (int i = 1; i <= M; ++i) {
        sz *= 2;
        vector<int> v = randN(sz);
        auto start = system_clock::now();
        int result = maxSubSum2(v);
        auto end = system_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        auto t = double(duration.count()) * microseconds::period::num / microseconds::period::den;
        out << t << std::endl;
    }
    return 0;
}

vector<int> randN(int n) {
    static default_random_engine e;
    static uniform_int_distribution<> u(-1000, 1000);
    vector<int> vi;
    for (int i = 0; i != n; ++i)
        vi.push_back(u(e));
    return vi;
}
