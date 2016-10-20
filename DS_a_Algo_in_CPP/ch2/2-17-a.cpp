//
// Created by paysonl on 16-10-20.
//

#include <vector>
using std::vector;

#include <iostream>

#include <cassert>

int min3(int a, int b, int c);
int minSubSum(const vector<int>& a);
int minSubRec(const vector<int>& a, int left, int right);

int main() {
    vector<int> v{-2, -1, -2, 3, -4};
    assert(minSubSum(v) == -6);

}

int minSubSum(const vector<int>& a) {
    return minSubRec(a, 0, a.size() - 1);
}

int minSubRec(const vector<int>& a, int left, int right) {
    if (left == right)
        if (a[left] < 0)
            return a[left];
        else
            return 0;

    int mid = (left + right) / 2;
    int minLeftSum = minSubRec(a, left, mid);
    int minRightSum = minSubRec(a, mid + 1, right);

    int minLeftBorderSum = 0, leftBorderSum = 0;
    for (int i = mid; i >= left; --i) {
        leftBorderSum += a[i];
        if (leftBorderSum < minLeftBorderSum)
            minLeftBorderSum = leftBorderSum;
    }

    int minRightBorderSum = 0, rightBorderSum = 0;
    for (int i = mid + 1; i <= right; ++i) {
        rightBorderSum += a[i];
        if (rightBorderSum < minRightBorderSum)
            minRightBorderSum = rightBorderSum;
    }
    return min3(minLeftSum, minRightSum, minLeftBorderSum + minRightBorderSum);
}
int min3(int a, int b, int c) {
    int min2 = a < b ? a : b;
    return min2 < c ? min2 : c;
}
