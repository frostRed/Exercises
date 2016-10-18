#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<vector<int>> v_iv{v1, v2, v3, v4, v5};

    vector<string> v6{10};
    vector<string> v7{10, "hi"};
    vector<vector<string>> v_sv{v6, v7};

    for (auto i: v_iv) {
        cout << "size is " << i.size() << endl;
        if (!i.empty())
            for (auto index: i)
                cout << index << "\t";
        cout << endl;
    }
    for (auto i: v_sv) {
        cout << "size is " << i.size() << endl;
        if (!i.empty())
            for (auto index: i)
                cout << index << "\t";
        cout << endl;
    }

    return 0;
}
