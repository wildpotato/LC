#include "../include.h"

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int reverse = 0;
        if (n <= 2) {
            return true;
        }
        for (int i = 1; i < n; ++i) {
            if (nums[i-1] > nums[i]) {
                reverse++;
            }
        } // for
        return (reverse <= 1);
    }
};

void test1() {
    vector<int> nums {4,2,3};
    Solution soln;
    assert(soln.checkPossibility(nums));
}

void test2() {
    vector<int> nums {4,2,1};
    Solution soln;
    assert(!soln.checkPossibility(nums));
}

void test3() {
    vector<int> nums {1,2,3,0,1,2,3};
    Solution soln;
    assert(!soln.checkPossibility(nums));
}

int main() {
    test1();
    test2();
    test3();
    cout << "Successful\n";
    return 0;
}
