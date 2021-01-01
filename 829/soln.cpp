#include "../include.h"

class Solution {
public:
    int consecutiveNumbersSum(int N) {

    }
};

void test() {
	Solution soln;
	assert(soln.consecutiveNumbersSum(5) == 2);
	assert(soln.consecutiveNumbersSum(9) == 3);
	assert(soln.consecutiveNumbersSum(15) == 4);
}

int main() {
	test();
	return 0;
}
