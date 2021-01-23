#include "../include.h"

class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

void test() {
    Solution soln;
    assert(soln.fib(2) == 1);
    assert(soln.fib(3) == 2);
    assert(soln.fib(4) == 3);
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
