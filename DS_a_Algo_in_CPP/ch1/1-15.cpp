//
// Created by paysonl on 16-10-18.
//

#include <cassert>
#include <vector>
using std::vector;

class CompArea;
class CompPeri;
class Rectangle {
    friend class CompArea;
    friend class CompPeri;
    friend bool operator==(const Rectangle& lhs, const Rectangle& rhs);
    friend bool operator!=(const Rectangle& lhs, const Rectangle& rhs);
public:
    Rectangle() = default;
    Rectangle(double l, double w): length{l}, width{w} {}

    double getLength() const {return length;}
    double getWidth() const {return width;}


private:
    double length;
    double width;
};

bool operator==(const Rectangle& lhs, const Rectangle& rhs) {
    if (lhs.length == rhs.length && lhs.width == rhs.width)
        return true;
    return false;
}
bool operator!=(const Rectangle& lhs, const Rectangle& rhs) {
    return !(lhs == rhs);
}

template <typename Object, typename Comparator>
const Object& findMax(const vector<Object>& v, Comparator cmp) {
    int indexMax = 0;
    for (int i = 0; i != v.size(); ++i)
        if (cmp(v[i], v[indexMax]))
            indexMax = i;
    return v[indexMax];
};

class CompArea {
public:
    bool operator()(const Rectangle& r1, const Rectangle& r2) const {
        return ((r1.length * r1.width) >
                (r2.length * r2.width));
    }

};
class CompPeri {
public:
    bool operator()(const Rectangle& r1, const Rectangle& r2) const {
        return ((r1.length + r1.width) >
                (r2.length + r2.width));
    }
};

int main() {
    vector<Rectangle> v{Rectangle(1, 2), Rectangle(0.5, 3), Rectangle(1.2, 1.2)};
    assert(findMax(v, CompArea()) == Rectangle(1, 2));
    assert(findMax(v, CompPeri()) == Rectangle(0.5, 3));
}
