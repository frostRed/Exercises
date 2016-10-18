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

int main() {
    vector<string> vs{"hello", "world"};
    auto iter = vs.begin();

    auto a = *iter++;
    //auto b = (*iter)++;
    //auto c = *iter.empty();
    auto d = iter->empty();
    //auto e = ++*iter;
    auto f = iter++->empty();
 
    return 0;
}
