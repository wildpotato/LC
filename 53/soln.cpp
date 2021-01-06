/*
 * This is a classical sliding window problem where
 * O(n) solution may be achieved via the sliding window
 * technique where typical brute force solution would
 * be O(n^2).
 *
 */
#include "../include.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = nums[0];
        int curr_sum = nums[0];
        for (int i = 1; i < n; ++i) {
            curr_sum = max(curr_sum + nums[i], nums[i]);
            max_sum = max(curr_sum, max_sum);
        }
        return max_sum;
    }
};

void test() {
    vector<int> nums1 {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums2 {1};
    vector<int> nums3 {0};
    vector<int> nums4 {-1};
    vector<int> nums5 {-2147483647};
    vector<int> nums6 {-2,1};
    vector<int> nums7 {-2,-1};
    Solution soln;
    assert(soln.maxSubArray(nums1) == 6);
    assert(soln.maxSubArray(nums2) == 1);
    assert(soln.maxSubArray(nums3) == 0);
    assert(soln.maxSubArray(nums4) == -1);
    assert(soln.maxSubArray(nums5) == -2147483647);
    assert(soln.maxSubArray(nums6) == 1);
    assert(soln.maxSubArray(nums7) == -1);
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
