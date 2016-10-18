#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <regex>
using std::regex;
using std::smatch;
#include <string>
using std::string;
#include <exception>
using std::regex_error;

int main() {
    string p1("[^c]ei");
    smatch s1;

    string word;
    cout << "Input a word(q to quit): ";
    cin >> word;
    while (word[0] != 'q' && word.size() > 1) {
        try {
            regex r1(p1);
            if (regex_search(word, s1, r1)) {
                cout << s1.str() << endl;
            } else {
                cout << "this word does not adopt." << endl;
            }
        }
        catch (regex_error e) {
            cout << e.what() << "\ncode: " << e.code() << endl;
        }
        cout << "Input a word(q to quit): ";
        cin >> word;
    }
}
