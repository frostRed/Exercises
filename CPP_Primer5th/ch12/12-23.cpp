#include <new>
#include <string>
#include <iostream>
#include <cstring>

int main() {
    char p1[] = "hello ";
    char p2[] = "world!";
    char *pch = new char[strlen(p1) + strlen(p2) - 1]();
    strcat(pch, p1);
    strcat(pch, p2);
    std::cout << pch << std::endl;

    std::string s = std::string("hello ") + std::string("world!");
    std::cout << s << std::endl;

}
