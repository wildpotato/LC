#include "../include.h"

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n);
        ret[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            ret[i] = nums[i] + ret[i-1];
        }
        return ret;
    }
};

void test() {
    vector<int> nums1 {1,2,3,4};
    vector<int> nums2 {1,1,1,1,1};
    vector<int> nums3 {3,1,2,10,1};
    vector<int> ret1 {1,3,6,10};
    vector<int> ret2 {1,2,3,4,5};
    vector<int> ret3 {3,4,6,16,17};
    Solution soln;
    assert(isArrayEqual(soln.runningSum(nums1), ret1));
    assert(isArrayEqual(soln.runningSum(nums2), ret2));
    assert(isArrayEqual(soln.runningSum(nums3), ret3));
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
