//
// Created by paysonl on 16-10-22.
//
#include "lib.h"

namespace lib {
    vector<int> randIntN(int n, int left, int right) {
        static default_random_engine e;
        static uniform_int_distribution<> u(left, right);
        vector<int> vi;
        for (int i = 0; i != n; ++i)
            vi.push_back(u(e));
        return vi;
    }

    vector<double> randDoubleN(int n, double left, double right) {
        static default_random_engine e;
        static uniform_real_distribution<> u(left, right);
        vector<double> vd;
        for (int i = 0; i != n; ++i)
            vd.push_back(u(e));
        return vd;
    }

    /*
    void time_count_int(Vecint2int f, int base, int times, string file) {
        ofstream out(file, ofstream::out);
        int sz = N;
        for (int i = 1; i <= M; ++i) {
            sz *= 2;
            vector<int> v = randIntN(sz);
            auto start = system_clock::now();
            int result = f(v);
            auto end = system_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            auto t = double(duration.count()) * microseconds::period::num / microseconds::period::den;
            out << t << std::endl;
        }
    }

    void time_count_double(Vecint2doub f, int base, int times, string file) {
        ofstream out(file, ofstream::out);
        int sz = N;
        for (int i = 1; i <= M; ++i) {
            sz *= 2;
            vector<double> v = randDoubleN(sz);
            auto start = system_clock::now();
            int result = f(v);
            auto end = system_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            auto t = double(duration.count()) * microseconds::period::num / microseconds::period::den;
            out << t << std::endl;
        }
    }
     */

}


