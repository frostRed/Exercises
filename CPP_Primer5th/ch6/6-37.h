#include <string>
using std::string;

using str_arr_10 = string[10];
str_arr_10& fun();

auto fun() -> string(&)[10];

string str_arr[10];
decltype(str_arr) &fun();
