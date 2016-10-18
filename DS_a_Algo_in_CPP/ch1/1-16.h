//
// Created by paysonl on 16-10-18.
//

#ifndef DS_A_ALGO_IN_CPP_1_16_H
#define DS_A_ALGO_IN_CPP_1_16_H

#include <vector>
using std::vector;

#include <stdexcept>
using std::out_of_range;

template <typename Object>
class Matrix {
public:
    Matrix(): array(0) {}
    Matrix(int rows, int cols): array(rows) {
        for (auto &thisRow: array)
            thisRow.resize(cols);
    }
    Matrix(const vector<vector<Object>>& v): array(v) {}
    Matrix(vector<vector<Object>>&& v): array(std::move(v)) {}

    const vector<Object>&operator[](int row) const {return array[row];}
    vector<Object>&operator[](int row) {return array[row];}

    int numrows() const {return array.size();}
    int numcols() const {return numrows() ? array[0].size() : 0;}

    void resize(int rows, int cols) {
        if (rows * cols > numrows() * numcols())
            throw out_of_range("the numbers of row and col are out of range");

        vector<vector<Object>> newarray(rows);
        for (auto &thisRow: newarray)
            thisRow.resize(cols);

        int r_old = 0;
        int c_old = 0;
        int r_new = 0;
        int c_new = 0;
        for (int i = 0; i != rows * cols; ++i) {
            newarray[r_new][c_new] = array[r_old][c_old];
            ++c_old;
            ++c_new;
            if (c_old == numcols()) {
                ++r_old;
                c_old = 0;
            }
            if (c_new == cols) {
                ++r_new;
                c_new = 0;
            }
        }
        array = std::move(newarray);
    }


private:
    vector<vector<Object>> array;
};

#endif //DS_A_ALGO_IN_CPP_1_16_H
