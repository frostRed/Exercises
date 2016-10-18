#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::ostream;


template <string::size_type H, string::size_type M>
class Screen {

public:
    using pos = string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}

    char get() const {
        return contents[cursor];
    }
    inline char get(pos row, pos col) const {
        return contents[row * width + col];
    }
    Screen &move(pos row, pos col);
    Screen &set(char);
    Screen &set(pos, pos, char);
    
    Screen &display(ostream &os) {
        do_display(os);
        return *this;
    }
    const Screen &display(ostream &os) const {
        do_display(os);
        return *this;
    }

private:
    pos cursor = 0;
    pos height = H;
    pos width = M;
    string contents;
    void do_display(ostream &os) const {
        os << contents;
    }
};

template <string::size_type H, string::size_type M>
inline Screen<H, M> &Screen<H, M>::move(pos row, pos col) {
    // 移动光标到指定位置
    cursor = row * width + col;
    return *this;
}
template <string::size_type H, string::size_type M>
inline Screen<H, M> &Screen<H, M>::set(char ch) {
    contents[cursor] = ch;
    return *this;
}
template <string::size_type H, string::size_type M>
inline Screen<H, M> &Screen<H, M>::set(pos row, pos col, char ch) {
    contents[row * width + col] = ch;
    return *this;
}


