#include "../include.h"

// pay attention to the indices!
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_sum (n, 0);
        vector<int> right_sum (n, 0);
        for (int i = 1; i < n; ++i) {
            left_sum[i] = left_sum[i-1] + nums[i-1];
        }
        for (int i = n-2; i >= 0; --i) {
            right_sum[i] = right_sum[i+1] + nums[i+1];
        }
        for (int i = 0; i < n; ++i) {
            if (left_sum[i] == right_sum[i]) {
                return i;
            }
        }
        return -1;
    }
};

void test() {
    vector<int> nums1 {1,7,3,6,5,6};
    vector<int> nums2 {1,2,3};
    vector<int> nums3 {2,1,-1};
    Solution soln;
    assert(soln.pivotIndex(nums1) == 3);
    assert(soln.pivotIndex(nums2) == -1);
    assert(isEqual(soln.pivotIndex(nums3), 0, 1e-9));
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
