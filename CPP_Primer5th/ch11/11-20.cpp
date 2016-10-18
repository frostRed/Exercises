#include <map>
#include <set>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <iostream>

int main(int argc, char *argv[]) {
    std::ifstream fin(argv[1]);
    std::map<std::string, size_t> word_count;
    std::set<std::string> exclude{"a", "an", "and", "the", "I"};
    std::string word;
    while (fin >> word) {
        auto beg = find_if(word.begin(), word.end(), isalpha);
        auto end = find_if(word.rbegin(), word.rend(), isalpha);

        if (beg != word.end()) { // 排除全是符号的
            std::string newWord;
            if (beg+1 == (end.base())) { // 单字母
                copy(beg, word.end(), back_inserter(newWord));
            } else {
                copy(beg, end.base(), back_inserter(newWord));
            }
            // 首字母大写统一转为小写
            char ch = tolower(newWord[0]);
            std::string lowerWord = newWord.insert(0, 1, ch).erase(1, 1);

            if (exclude.find(newWord) == exclude.end() &&
                    exclude.find(lowerWord) == exclude.end()) {
                //++word_count[lowerWord];
                auto ret = word_count.insert({lowerWord, 1});
                if (!ret.second) {
                    ++ret.first->second;
                }
            }
         }
    }
    for (const auto &i: word_count) {
        std::cout << i.first << "\t" << i.second << (i.second > 1 ? " times" : "time") << std::endl;
    }

    return 0;
}
