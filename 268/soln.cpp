#include "../include.h"

class Solution {
public:
    int missingNumber(vector<int>& nums) {
		int n = nums.size();
		int sum = n * (n+1) / 2;
		for (int i : nums) {
			sum -= i;
		}
		return sum;
    }
};

void test() {
	vector<int> nums1 {3,0,1};
	vector<int> nums2 {0,1};
	vector<int> nums3 {9,6,4,2,3,5,7,0,1};
	Solution soln;
	assert(soln.missingNumber(nums1) == 2);
	assert(soln.missingNumber(nums2) == 2);
	assert(soln.missingNumber(nums3) == 8);
}

int main() {
	test();
	cout << "Successful\n";
	return 0;
}
