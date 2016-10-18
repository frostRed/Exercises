
class Base {
protected:
    int prot_mem;
};

class Sneaky: public Base {
    friend void clobber(Sneaky &);
    friend void clobber(Base &);
    int j;
};

void clobber(Sneaky &s) {
    s.j = s.prot_mem = 0;
}
void clobber(Base &b) {
    b.prot_mem = 0;
}

int main() {
}
