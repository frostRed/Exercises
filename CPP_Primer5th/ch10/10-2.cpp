#include <algorithm>
#include <list>
#include <string>
#include <iostream>

int main() {
    std::list<std::string> str_li;
    std::string word;
    while (std::cin >> word)
        str_li.push_back(word);
    std::cout << count(str_li.begin(), str_li.end(), word) << std::endl;
    return 0;
}
