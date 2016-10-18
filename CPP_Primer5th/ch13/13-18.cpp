#include <string>
#include <iostream>

using std::string;

class Employee {
public:
    Employee(): num(++init_id) {}
    Employee(const string &s): name(s), num(++init_id) {}

    Employee(const Employee &e): name(e.name), num(++init_id) {}

    int id() const {return num;}

private:
    string name;
    int num;
    static int init_id;
    static int init() {return 0;}

};

int Employee::init_id = init();

int main() {
    Employee e1;
    Employee e2(e1);
    Employee e3 = e1;

    Employee e4;
    e4 = e3;

    std::cout << e1.id() << e2.id() << e3.id() << e4.id() << std::endl;
    
}
