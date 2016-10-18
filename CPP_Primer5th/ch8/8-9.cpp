#include <sstream>
#include "8-1.h"
using std::istringstream;

int main() {
    string s("abcdefg");
    istringstream iss(s);
    fun(iss);

    return 0;
}
