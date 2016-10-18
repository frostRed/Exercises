

class Base {
public:
    void pub_mem();
protected:
    int prob_mem;
private:
    char priv_mem;
};

///////////////////////
class Pub_Derv: public Base {
public:
    int f() {return prob_mem;}
    void memfcn(Base &b) { b = *this; }
};
class Prot_Derv: protected Base {
public:
    int f2() {return prob_mem;}
    void memfcn(Base &b) { b = *this; }
};

class Priv_Derv: private Base {
public:
    int f1() {return prob_mem;}
    void memfcn(Base &b) { b = *this; }
};
////////////////////////////

class Derived_from_Public: public Pub_Derv {
public:
    void memfcn(Base &b) { b = *this; }
};
class Derived_from_Private: public Priv_Derv {
public:
    //void memfcn(Base &b) { b = *this; }
};
class Derived_from_Protected: public Prot_Derv {
public:
    void memfcn(Base &b) { b = *this; }
};

int main() {
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Private dd2;
    Derived_from_Protected dd3;

    Base *p = &d1;
    //p = &d2;
    //p = &d3;
    p = &dd1;
    //p = &dd2;
    //p = &dd3;
}
