#include "../include.h"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> nums_seen;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) {
                nums_seen.erase(nums_seen.find(nums[i-k-1]));
            }
            if (nums_seen.find(nums[i]) != nums_seen.end()) {
                return true;
            }
            nums_seen.insert(nums[i]);
        }
        return false;
    }
};

void test() {
    vector<int> nums1 {1,2,3,1};
    vector<int> nums2 {1,0,1,1};
    vector<int> nums3 {1,2,3,1,2,3};
    int k1 = 3, k2 = 1, k3 = 2;
    Solution soln;
    assert(soln.containsNearbyDuplicate(nums1, k1));
    assert(soln.containsNearbyDuplicate(nums2, k2));
    assert(!soln.containsNearbyDuplicate(nums3, k3));
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
