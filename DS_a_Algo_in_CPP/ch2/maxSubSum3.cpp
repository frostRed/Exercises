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
int maxSumRec(const vector<int>& a, int left, int right);
int max3(int, int, int);

int maxSubSum3(const vector<int>& a) {
    return maxSumRec(a, 0, a.size() - 1);
}

int main(int argc, char** argv) {
    int N = std::stoi(argv[1]);
    int M = std::stoi(argv[2]);

    ofstream out("time3", ofstream::out);

    int sz = N;
    for (int i = 1; i <= M; ++i) {
        sz *= 2;
        vector<int> v = randN(sz);
        auto start = system_clock::now();
        int result = maxSubSum3(v);
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

int maxSumRec(const vector<int>& a, int left, int right) {
    if (left == right)
        if (a[left] > 0)
            return a[left];
        else
            return 0;

    int center = (left + right) / 2;
    int maxLeftSum = maxSumRec(a, left, center);
    int maxRightSum = maxSumRec(a, center + 1, right);

    int maxLeftBorderSum = 0, leftBorderSum = 0;
    for (int i = center; i >= left; --i) {
        leftBorderSum += a[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    int maxRightBorderSum = 0, rightBorderSum = 0;
    for (int i = center + 1; i <= right; ++i) {
        rightBorderSum += a[i];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);

}

int max3(int i1, int i2, int i3) {
    int max2 = i1 > i2 ? i1 : i2;
    return max2 > i3 ? max2 : i3;
}
