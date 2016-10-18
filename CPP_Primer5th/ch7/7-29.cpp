#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::ostream;
using std::cout;

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
    Screen move(pos row, pos col);
    Screen set(char);
    Screen set(pos, pos, char);
    Screen display(ostream &os) {
        do_display(os);
        return *this;
    }
    const Screen display(ostream &os) const {
        do_display(os);
        return *this;
    }


private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    string contents;
    void do_display(ostream &os) const {
        os << contents;
    }
};

inline Screen Screen::move(pos row, pos col) {
    // 移动光标到指定位置
    cursor = row * width + col;
    return *this;
}
inline Screen Screen::set(char ch) {
    contents[cursor] = ch;
    return *this;
}
inline Screen Screen::set(pos row, pos col, char ch) {
    contents[row * width + col] = ch;
    return *this;
}



class Window_mgr {
private:
    vector<Screen> screens{Screen(24, 80, ' ')};
};

int main() {
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
    
    return 0;
}
