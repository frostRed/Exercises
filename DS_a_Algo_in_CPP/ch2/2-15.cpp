//
// Created by paysonl on 16-10-19.
//

#include <cassert>

#include <vector>
using std::vector;

bool find_exist_rec(const vector<int>& A, int low, int high);

bool find_exist(const vector<int>& A) {
    // must A1 < A2 < A3 < An
    // find if exists Ai == i
    find_exist_rec(A, 0, A.size() - 1);

}

bool find_exist_rec(const vector<int>& A, int low, int high) {
    int mid = (low + high) / 2;
    if (A[mid] == mid + 1)
        return true;
    else if (A[mid] > mid + 1)
        return find_exist_rec(A, low, mid - 1);
}

int main() {
    vector<int> v1{1, 2, 3, 5, 6, 7, 8, 9, 10};
    vector<int> v2{1, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v3{2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(find_exist(v1));
    assert(find_exist(v2));
    assert(!find_exist(v3));
}
