#include <functional>
#include <iostream>
#include <string>
#include <map>

using std::string;
using std::map;
using std::function;

int main() {
    map<string, function<double (double, double)>> double_bin_ops = {
            {"+", std::plus<double>()},
            {"-", std::minus<double>()},
            {"*", std::multiplies<double>()},
            {"/", std::divides<double>()},
    };


    string input;
    getline(std::cin, input);

    const string ops = "+-*/";
    auto pos = input.find_first_of(ops);
    if  (pos <= input.size()) {
        double lhs = stod(input.substr(0, pos));
        double rhs = stod(input.substr(pos+1));
        string exc = input.substr(pos, 1);
        double ret = double_bin_ops[exc](lhs, rhs);

        std::cout << ret << std::endl;
        return 0;
    }
    return -1;
}
