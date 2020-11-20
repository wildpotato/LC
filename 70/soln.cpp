#include "../include.h"

class Solution {
public:
    int climbStairs(int n) {
		vector<int> ways;
		ways.resize(n+1, -1);
    	ways[0] = 1;
		ways[1] = 1;
		for (int i = 2; i <= n; i++) {
			ways[i] = ways[i-1] + ways[i-2];
		}
		return ways[n];
	}
};

void test1() {
	Solution soln;
	assert(soln.climbStairs(3) == 3);
}

void test2() {
	Solution soln;
	assert(soln.climbStairs(2) == 2);
}

int main() {
	test1();
	test2();
	cout << "Successful\n";
	return 0;
}
