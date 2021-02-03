#include "../include.h"

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime(i)) {
                count++;
            }
        }
        return count;
    }

    bool isPrime(int num) {
        int sq_rt = floor(sqrt(num));
        for (int i = 2; i <= sq_rt; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
};

void test() {
    Solution soln;
    assert(soln.countPrimes(10) == 4);
    assert(soln.countPrimes(0) == 0);
    assert(soln.countPrimes(1) == 0);
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
