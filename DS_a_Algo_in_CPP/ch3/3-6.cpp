//
// Created by paysonl on 16-10-22.
//

#include "List.h"
#include "Vector.h"

#include <list>
#include <vector>

#include <iostream>

#include <fstream>
using std::ofstream;

#include <chrono>
using std::chrono::system_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;

Vector<int> jeseplus(int m, int n) {
    List<int> peoples;
    for (int i = 0; i != n; ++i)
        peoples.push_back(i + 1);

    auto ite = peoples.begin();
    Vector<int> del_order;
    while (peoples.sz() > 1) {
        for (int i = 0; i != m; ++i) {
            ++ite;
            // it ite at end(), must came to begin()
            if (ite == peoples.end())
                ite = peoples.begin();
        }
        del_order.push_back(*ite);
        ite = peoples.erase(ite);
        // it ite at end(), must came to begin()
        if (ite == peoples.end())
            ite = peoples.begin();
    }
    del_order.push_back(peoples.front());
    return del_order;
}

std::vector<int> jeseplus_STL(int m, int n) {
    std::list<int> peoples;
    for (int i = 0; i != n; ++i)
        peoples.push_back(i + 1);

    auto ite = peoples.begin();
    std::vector<int> del_order;
    while (peoples.size() > 1) {
        for (int i = 0; i != m; ++i) {
            ++ite;
            // it ite at end(), must came to begin()
            if (ite == peoples.end())
                ite = peoples.begin();
        }
        del_order.push_back(*ite);
        ite = peoples.erase(ite);
        // it ite at end(), must came to begin()
        if (ite == peoples.end())
            ite = peoples.begin();
    }
    del_order.push_back(peoples.front());
    return del_order;
}

int main(int argc, char** argv) {
    // N is base count, M is run times
    const int N = std::stoi(argv[1]);
    const int M = std::stoi(argv[2]);

    ofstream out("joseplus_time", ofstream::out);
    int sz = N;
    for (int i = 0; i != M; ++i) {
        sz *= (i == 0 ? 1 : 2);
        auto start = system_clock::now();
        jeseplus(1, sz);
        auto end = system_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        auto t = double(duration.count()) * microseconds::period::num / microseconds::period::den;
        out << t << std::endl;
    }

    ofstream out2("joseplus_STL_time", ofstream::out);
    sz = N;
    for (int i = 0; i != M; ++i) {
        sz *= (i == 0 ? 1 : 2);
        auto start = system_clock::now();
        jeseplus_STL(1, sz);
        auto end = system_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        auto t = double(duration.count()) * microseconds::period::num / microseconds::period::den;
        out2 << t << std::endl;
    }
}
