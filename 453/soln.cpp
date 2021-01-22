#include "../include.h"

/*
 * The key observation in solving this problem is to
 * understand that incrementing one to n-1 elements is
 * the same as decrementing single element by 1. This is
 * very much like in combinatorics where n choose n-1 is
 * mathematically the same as n choose 1.
 *
 * Once we have that cleared, the solution is a simple O(n)
 * time and O(1) space complexity.
 *
 */
class Solution {
public:
    int minMoves(vector<int>& nums) {
		// here the two vars are declared long to avoid integer overflow
		long min = INT_MAX;
		long total = 0;
		int n = nums.size();
		if (n <= 1) return 0;
		for (int i = 0; i < n; ++i) {
			if (nums[i] < min) {
				min = nums[i];
			}
			total += nums[i];
		}
		return total - n * min;
    }
};

void test() {
	vector<int> input {1,2,3};
	Solution soln;
	assert(soln.minMoves(input) == 3);
}

int main() {
	test();
	cout << "Successful\n";
	return 0;
}
