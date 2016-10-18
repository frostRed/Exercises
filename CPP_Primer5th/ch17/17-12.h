#include <bitset>
using std::bitset;
#include <string>
using std::string;

template <unsigned N>
struct Data {
    Data() = default;
    Data(const bitset<N> &b): answers(b) {}
    Data(const string &s): answers(s) {}

    bool test_n(unsigned n) { return answers.test(n); }
    void set(unsigned no, bool ans) { answers.set(no, ans); }

private:
    bitset<N> answers;
};

static Data<10> d("0101110011");

void update(unsigned no, bool ans) {
    d.set(no, ans);
}