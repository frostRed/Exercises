#include <bitset>
using std::bitset;
#include <string>
using std::string;

template <unsigned N>
struct Data {
public:
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

double grade(const Data &teacher, const Data &stu) {
    auto sz = (teacher.size() > stu.size()) ? stu.size() : teacher.size();
    double cnt = 0;
    for (decltype(sz) i = 0; i != sz(); ++i) {
        if (teacher[i] = stu[i]) {
            ++cnt;
        }
    }
    return cnt / teacher.size();
}
