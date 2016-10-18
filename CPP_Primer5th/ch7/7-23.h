#include <string>
#include <vector>
using std::string;
using std::vector;


class Screen {
public:
    using pos = string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}

    char get() const {
        return contents[cursor];
    }
    inline char get(pos row, pos col) const {
        return contents[row * width + col];
    }
    Screen &move(pos row, pos col);


private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    string contents;
};

inline Screen &Screen::move(pos row, pos col) {
    // 移动光标到指定位置
    cursor = row * width + col;
    return *this;
}


class Window_mgr {

private:
    vector<Screen> screens{Screen(24, 80, ' ')};
};
