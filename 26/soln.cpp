#include "../include.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int last, i = 1;
        if (size <= 1) {
            return size;
        }
        last = nums[0];
        for (; i < size ;) {
            if (nums[i] == last) {
                size--;
                nums.erase(nums.begin() + i);
            } else {
                last = nums[i];
                i++;
            }
        }
        return size;
    }
};

bool isArrayEqual(vector<int> a, vector<int> b) {
    if (a.size() != b.size()) {
        return false;
    }
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void test1() {
    Solution soln;
    vector<int> nums {1,1,2};
    vector<int> ret {1,2};
    assert(soln.removeDuplicates(nums) == 2);
    assert(isArrayEqual(nums, ret));
}

void test2() {
    Solution soln;
    vector<int> nums {0,0,1,1,1,2,2,3,3,4};
    vector<int> ret {0,1,2,3,4};
    assert(soln.removeDuplicates(nums) == 5);
    assert(isArrayEqual(nums, ret));
}

void test3() {
    Solution soln;
    vector<int> nums {};
    vector<int> ret {};
    assert(soln.removeDuplicates(nums) == 0);
    assert(isArrayEqual(nums, ret));
}
int main() {
    test1();
    test2();
    test3();
    cout << "Successful\n";
    return 0;
}
