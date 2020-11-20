#include "../include.h"

class Solution {
public:
    int climbStairs(int n) {
		int a = 1;
		int b = 1;
		int c = 0;
		if (n == 0 || n == 1) {
			return 1;
		}
		for (int i = 2; i <= n; i++) {
			c = a + b;
			a = b;
			b = c;
		}
		return c;
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
