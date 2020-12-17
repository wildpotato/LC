#include "../include.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		constexpr int MAX_NUM_DUPLICATES = 2;
		int n = nums.size();
        int count = MAX_NUM_DUPLICATES;
		if (n <= MAX_NUM_DUPLICATES) {
			return n;
		}
        /* count is the index to the number that needs to be replaced */
        for (int i = MAX_NUM_DUPLICATES; i < n; ++i) {
            if (nums[count - MAX_NUM_DUPLICATES] != nums[i]) {
                nums[count] = nums[i];
                count++;
            }
        }
		return count;
	}
};

void test1() {
	vector<int> input {1,1,1,2,2,3};
	vector<int> golden {1,1,2,2,3};
	Solution soln;
	int len = soln.removeDuplicates(input);
	assert(isArrayEqual(input, golden, len));
}

void test2() {
	vector<int> input {0,0,1,1,1,1,2,3,3};
	vector<int> golden {0,0,1,1,2,3,3};
	Solution soln;
	int len = soln.removeDuplicates(input);
	assert(isArrayEqual(input, golden, len));
}

int main() {
	test1();
	test2();
	cout << "Successful\n";
	return 0;
}
