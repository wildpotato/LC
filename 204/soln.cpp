#include "../include.h"

// The sqrt() function is simply too expensive and may cause
// TLE (time limit exceeded) on Leetcode server, therefore we
// must use a little trick to achieve the same logic.
// The Sieve of Eratosthenes uses an extra O(n) memory and its runtime complexity is O(n log log n).
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> is_prime(n, true);
        for (int i = 0; i < 2 && i < n; ++i) {
            is_prime[i] = false;
        }
        for (int i = 2; i * i < n; i++) {
            if (!is_prime[i]) {
                continue;
            }
            for (int j = i * i; j < n; j += i) {
                is_prime[j] = false;
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (is_prime[i]) {
                count++;
            }
        }
        return count;
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
