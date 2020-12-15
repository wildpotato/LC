#include "../include.h"

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret (nums1.size(), -1);

        for (int i = 0; i < nums1.size(); ++i) {
            auto pos = find(nums2.begin(), nums2.end(), nums1[i]);
            bool found = false;
            while (++pos != nums2.end()) {
                if (*pos > nums1[i]) {
                    ret[i] = *pos;
                    break;
                }
            } // while
        } // for
        return ret;
    }
};

void test1() {
    vector<int> nums1 {4,1,2};
    vector<int> nums2 {1,3,4,2};
    vector<int> golden {-1,3,-1};
    Solution soln;
    assert(isArrayEqual(soln.nextGreaterElement(nums1, nums2), golden));
}

void test2() {
    vector<int> nums1 {2,4};
    vector<int> nums2 {1,2,3,4};
    vector<int> golden {3,-1};
    Solution soln;
    assert(isArrayEqual(soln.nextGreaterElement(nums1, nums2), golden));
}

int main() {
    test1();
    test2();
    cout << "Successful\n";
    return 0;
}
