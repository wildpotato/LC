#include "../include.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    }
};

void test() {
    vector<int> nums1 {1,2,3,0,0,0};
    vector<int> nums2 {2,5,6};
    vector<int> ret {1,2,2,3,5,6};
    Solution soln;
    assert(isArrayEqual(soln.merge(nums1, nums2), ret));
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
