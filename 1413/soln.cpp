#include "../include.h"

class Solution {
public:
    int minStartValue(vector<int>& nums) {
		int min = INT_MAX;
		int sum = 0;
		for (int i = 0; i < nums.size(); ++i) {
			sum += nums[i];
			if (sum < min) {
				min = sum;
			}
		}
		if (min < 0) {
			return 1 - min;
		}
		return 1;
    }
};

void test() {
	vector<int> nums1 {1,2};
	vector<int> nums2 {1,-2,-3};
	vector<int> nums3 {-3,2,-3,4,2};
	Solution soln;
	assert(soln.minStartValue(nums1) == 1);
	assert(soln.minStartValue(nums2) == 5);
	assert(soln.minStartValue(nums3) == 5);
}

int main() {
	test();
	cout << "Successful\n";
	return 0;
}
