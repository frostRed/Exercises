
struct Foo {
    int operator()(int val1, int val2, int val3) {
        return val1 ? val2 : val3;
    }
};
