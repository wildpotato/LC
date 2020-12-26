#include "../include.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		int lastNonZeroFoundAt = 0;
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			if (nums[i] != 0) {
				nums[lastNonZeroFoundAt++] = nums[i];
			}
		}
		for (int i = lastNonZeroFoundAt; i < n; ++i) {
			nums[i] = 0;
		}
    }
};

void test() {
	vector<int> input {0,1,0,3,12};
	vector<int> output {1,3,12,0,0};
    Solution soln;
	soln.moveZeroes(input);
	printArray(input);
	assert(isArrayEqual(input, output));
}

int main() {
	test();
	return 0;
}
