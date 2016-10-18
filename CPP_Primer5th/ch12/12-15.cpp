#include <memory>


void f(destination &d) {
    connection c = connect(&d);

    std::shared_ptr<connection> p(&c, [](connection *p){end_connection(p)});
}
