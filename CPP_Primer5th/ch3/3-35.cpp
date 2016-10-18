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
    int arr[] = {1, 2, 3};
    for (auto i = begin(arr); i != end(arr) ; ++i){
        *i = 0;
        cout << *i << endl;
    }

 
    return 0;
}
