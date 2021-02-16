#include "../include.h"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

    }
};

void test() {
    vector<int> nums1 {1,2,3,1};
    vector<int> nums2 {1,0,1,1};
    vector<int> nums3 {1,2,3,1,2,3};
    int k1 = 3, k2 = 1, k3 = 2;
    Solution soln;
    assert(soln.containsNearByDuplicate(nums1, k1));
    assert(soln.containsNearByDuplicate(nums2, k2));
    assert(!soln.containsNearByDuplicate(nums3, k3));
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
