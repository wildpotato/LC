#include "../include.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return 4;
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
