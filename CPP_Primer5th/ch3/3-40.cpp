#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

int main() {
    char c1[] = "hello";
    char c2[] = "world";
    char c3[20];
    strcpy(c3, c1);
    strcat(c3, c2);
    cout << c3 << endl;
    return 0;
}
