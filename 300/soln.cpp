#include "../include.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		size_t n = nums.size();
		int ret = 0;
		vector<int> dp(n + 1, 1);
		if (n == 0) {
			return 0;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[j] < nums[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			ret = max(ret, dp[i]);
		}
        return ret;
    }
};

void test1() {
    Solution soln;
    vector<int> nums {10,9,2,5,3,7,101,18};
    assert(soln.lengthOfLIS(nums) == 4);
}

void test2() {
    Solution soln;
    vector<int> nums {0,1,0,3,2,3};
    assert(soln.lengthOfLIS(nums) == 4);
}

void test3() {
    Solution soln;
    vector<int> nums {7,7,7,7,7,7,7};
    assert(soln.lengthOfLIS(nums) == 1);
}
int main() {
    test1();
    cout << "Successful\n";
    return 0;
}
