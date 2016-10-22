//
// Created by paysonl on 16-10-22.
//

#ifndef DS_A_ALGO_IN_CPP_LIB_H
#define DS_A_ALGO_IN_CPP_LIB_H

#include <fstream>
using std::ofstream;

#include <random>
using std::default_random_engine;
using std::uniform_int_distribution;
using std::uniform_real_distribution;

#include <chrono>
using std::chrono::system_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <initializer_list>
using std::initializer_list;

namespace lib {
    typedef int Vecint2int(const vector<int>&);
    typedef double Vecdoub2doub(const vector<double>&);

    vector<int> randIntN(int n, int left = 0, int right = 10);
    vector<double> randDoubleN(int n, double left = 0, double right = 1);
    //void time_count_int(Vecint2int f, int base, int times, string file);
    //void time_count_double(Vecint2doub f, int base, int times, string file);

    template <typename Fun, typename T>
    void time_count_int(Fun f, const vector<T>& v, int base, int times, string file, int left, int right) {
        ofstream out(file, ofstream::out);
        int sz = base;
        for (int i = 0; i < times; ++i) {
            // first time begin at base
            sz *= (i == 0 ? 1 : 2);
            decltype(v) args;
            for (auto &i: v) {
                args.push_back(randIntN(sz), left, right);
            }

            auto start = system_clock::now();
            f(args);
            auto end = system_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            auto t = double(duration.count()) * microseconds::period::num / microseconds::period::den;
            out << t << std::endl;
        }
    }

    template <typename Fun, typename T>
    void time_count_doub(Fun f, const vector<T>& v, int base, int times, string file, int left = 0, int right = 1) {
        ofstream out(file, ofstream::out);
        int sz = base;
        for (int i = 0; i < times; ++i) {
            // first time begin at base
            sz *= (i == 0 ? 1 : 2);
            decltype(v) args;
            for (auto &i: v) {
                args.push_back(randDoubleN(sz, left, right));
            }

            auto start = system_clock::now();
            f(args);
            auto end = system_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            auto t = double(duration.count()) * microseconds::period::num / microseconds::period::den;
            out << t << std::endl;
        }
    }


}

#endif //DS_A_ALGO_IN_CPP_LIB_H
