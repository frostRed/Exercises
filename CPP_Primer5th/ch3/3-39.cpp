#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int f1(string s1, string s2) {
    auto size1 = s1.size();
    auto size2 = s2.size();
    for (decltype(size1) i = 0; i <= size1 && i <= size2; ++i) {
        if (s1[i] < s2[i] ||(i == size1 && i < size2))
            return -1;
        else if (s1[i] > s2[i] ||(i == size2 && i < size1))
            return 1;
        else if (i == size1 && i == size2)
            return 0;
        else if (s1[i] == s2[i])
            continue;;
    }
}

int f2(char *c1, char* c2) {
    while (*c1 != '\0' && *c2 != '\0') {
        if (*c1 > *c2)
            return 1;
        else if (*c1 < *c2)
            return -1;
        else {
            ++c1;
            ++c2;
        }
    }
    if (*c1 == '\0' && *c2 != '\0')
        return -1;
    else if (*c1 != '\0' && *c2 == '\0')
        return 1;
    else
        return 0;
}
int main() {
    string s1{"Abc"};
    string s2{"Ab"};
    
    char carr1[] = "Ab";
    char carr2[] = "abc";
 
    cout << f1(s1, s2) << endl;
    cout << f2(carr1, carr2) << endl;

    return 0;
}
