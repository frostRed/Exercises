#include <map>
#include <set>
#include <string>
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
    std::ifstream fin(argv[1]);
    std::map<std::string, size_t> word_count;
    std::set<std::string> exclude{"a", "an", "and", "the", "I"};
    std::string word;
    while (fin >> word) {
        if (exclude.find(word) == exclude.end())
            ++word_count[word];
    }
    for (const auto &i: word_count) {
        std::cout << i.first << "\t" << i.second << (i.second > 1 ? " times" : "time") << std::endl;
    }

    return 0;
}
