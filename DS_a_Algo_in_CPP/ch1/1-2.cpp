//
// Created by paysonl on 16-10-18.
//

#include <iostream>
using std::cout;
using std::endl;

#include <set>
using std::set;

#include <string>
using std::string;

#include <vector>
using std::vector;

void run(const vector<vector<string>>&, const set<string>&);
void add_alph(const vector<vector<string>>& alph_map, const set<string>& words, string test, int orientation, unsigned long i, unsigned long j);

int main() {
    vector<vector<string>> alph_map{{"t", "h", "i", "s"},
                                    {"w", "a", "t", "s"},
                                    {"o", "a", "h", "g"},
                                    {"f", "g", "d", "t"}};

    set<string> words{"this", "two", "fat", "that"};

    run(alph_map, words);

}

void run(const vector<vector<string>>& alph_map, const set<string>& words) {
    int N = alph_map.size();
    for (auto i = 0; i != N; ++i) {
        for (auto j = 0; j != N; ++j) {
            string test;
            for (int orien = 1; orien != 9; ++orien)
                add_alph(alph_map, words, test, orien, i, j);
        }
    }
}

void add_alph(const vector<vector<string>>& alph_map, const set<string>& words, string test, int orientation, unsigned long i,
              unsigned long j) {
    int N = alph_map.size();
    while (i >= 0 && i < N && j >= 0 && j < N) {
        test += alph_map[i][j];

        if (orientation == 1) {
            ++i;
        }
        if (orientation == 2) {
            --i;
        }
        if (orientation == 3) {
            ++j;
        }
        if (orientation == 4) {
            --j;
        }
        if (orientation == 5) {
            ++i;
            ++j;
        }
        if (orientation == 6) {
            --i;
            --j;
        }
        if (orientation == 7) {
            ++i;
            --j;
        }
        if (orientation == 8) {
            --i;
            ++j;
        }

        if (words.find(test) == words.end())
            continue;
        else
            cout << test << endl;
    }
}