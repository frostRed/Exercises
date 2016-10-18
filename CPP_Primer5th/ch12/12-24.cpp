#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    cout << "what sizes do you want?: ";
    int size{0};
    cin >> size;

    char *p = new char[size + 1]();
    // 读取多余回车
    cin.ignore();
    cout << "input the content: ";
    cin.get(p, size+1);

    cout << p << endl;
    delete [] p;

    return 0;
}
