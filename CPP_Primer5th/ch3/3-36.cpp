#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;

bool f1(int arr1[], int arr2[], int n) {
    auto beg1 = arr1;
    auto end1 = arr1 + n;
    auto beg2 = arr2;
    auto end2 = arr2 + n;
    if ((end1 - beg1) != (end2 - beg2))
        return false;
    else {
        while (*beg1 == *beg2) {
            ++beg1;
            ++beg2;
            if (beg1 == end1)
                return true;
        }
        return false;
    }
}
bool f2(vector<int> vi1, vector<int> vi2) {
    if (vi1.size() != vi2.size())
        return false;
    else {
        for (decltype(vi1.size()) i = 0; i < vi1.size(); ++i) {
            if (vi1[i] == vi2[i])
                break;
            else
                return false;
        }
        return true;
    }
}
int main() {
    int arr1[] = {1, 2};
    int arr2[] = {1, 3, 4};

    vector<int> vi1{1, 2};
    vector<int> vi2{1, 2};

    cout << f1(arr1, arr2, 3) << endl;
    cout << f2(vi1, vi2) << endl;
 
    return 0;
}

