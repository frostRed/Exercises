#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
void f1() {
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<vector<int>> v_iv{v1, v2, v3, v4, v5};

    vector<string> v6{10};
    vector<string> v7{10, "hi"};
    vector<vector<string>> v_sv{v6, v7};

    for (auto b = v_iv.cbegin(); b != v_iv.cend(); ++b) {
        cout << "size is " << b->size() << endl;
        if (!b->empty())
            for (auto bb = b->cbegin(); bb != b->cend(); ++bb) 
                cout << *bb << "\t";
        cout << endl;
    }

    for (auto b = v_sv.cbegin(); b != v_sv.cend(); ++ b) {
        cout << "size is " << b->size() << endl;
        if (!b->empty())
            for (auto bb = b->cbegin(); bb != b->cend(); ++bb)
                cout << *bb << "\t";
        cout << endl;
    }
}
void f2() {
    vector<string> sv;
    string s;
    while (cin >> s)
        sv.push_back(s);

    for (auto b = sv.begin(); b != sv.end(); ++b) {
        for (auto bb = b->begin(); bb != b->end(); ++bb)
            *bb = toupper(*bb);
        cout << *b << endl;
    }

}

int main() {
    f1();
    //f2();

    return 0;
}
