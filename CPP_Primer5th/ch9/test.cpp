#include <iostream>
#include <deque>
#include  <cmath>
class DigPow
{
public:
  static int digPow(int n, int p);
};

int DigPow::digPow(int n, int p) {
    int n_bak = n;
    std::deque<int> iv;
    while (n) {
        iv.push_front(n % 10);
        n = (n - iv.front()) / 10;
    }
    int nk = 0;
    for (decltype(iv.size()) i = 0; i != iv.size(); ++i) {
        nk += pow(iv[i], p++);
    }
    
    std::cout << nk << std::endl;
    if (nk % n_bak == 0)
        return nk / n_bak;
    else
	    return -1;
}     

int main() {
    std::cout << DigPow::digPow(89, 1) << std::endl; 
    std::cout << DigPow::digPow(46288, 3) << std::endl; 

    return 0;
}
