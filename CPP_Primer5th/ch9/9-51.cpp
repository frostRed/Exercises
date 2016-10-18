#include <string>
using std::string;
class Date {
public:
    Date() = default;
    Date(string &s);

private:
    unsigned year;
    unsigned month;
    unsigned day;
};
