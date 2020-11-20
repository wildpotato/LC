#include "../include.h"

class Solution {
public:
    int climbStairs(int n) {
		vector<int> ways;
		ways.resize(n+1, -1);
		return countWays(n, ways);
    }

	int countWays(int n, vector<int> ways) {
		if (n < 0) return 0;
		else if (n == 0) return 0;
		else if (ways[n] != -1) return ways[n];
		else {
			ways[n] = countWays(n-1, ways) + countWays(n-2, ways);
			return ways[n];
		}
	}
};

void test1() {
	Solution soln;
	assert(soln.climbStairs(3) == 3);
}

int main() {
	cout << "Successful\n";
	return 0;
}
