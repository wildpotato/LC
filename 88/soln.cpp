#include "../include.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = m > 0 ? m-1 : 0;
        int ptr2 = n-1;
        int ptr_insert = m+n-1;
        while (ptr1 >= 0 and ptr2 >= 0) {
            if (nums1[ptr1] > nums2[ptr2]) {
                nums1[ptr_insert--] = nums1[ptr1];
                nums1[ptr1--] = nums2[ptr2--];
            } else {
                nums1[ptr_insert--] = nums2[ptr2--];
            }
        }
    }
};

void test1() {
    vector<int> nums1 {1,2,3,0,0,0};
    vector<int> nums2 {2,5,6};
    vector<int> ret {1,2,2,3,5,6};
    Solution soln;
    soln.merge(nums1, 3, nums2, 3);
    assert(isArrayEqual(ret, nums1));
}

void test2() {
    vector<int> nums1 {0};
    vector<int> nums2 {1};
    vector<int> ret {1};
    Solution soln;
    soln.merge(nums1, 0, nums2, 1);
    //printArray(nums1);
    assert(isArrayEqual(ret, nums1));
}

void test3() {
    vector<int> nums1 {2,0};
    vector<int> nums2 {1};
    vector<int> ret {1,2};
    Solution soln;
    soln.merge(nums1, 1, nums2, 1);
    assert(isArrayEqual(ret, nums1));
}

void test4() {
    vector<int> nums1 {4,5,6,0,0,0};
    vector<int> nums2 {1,2,3};
    vector<int> ret {1,2,3,4,5,6};
    Solution soln;
    soln.merge(nums1, 3, nums2, 3);
    printArray(nums1);
    assert(isArrayEqual(ret, nums1));
}

void test5() {
    vector<int> nums1 {4,0,0,0,0,0};
    vector<int> nums2 {1,2,3,5,6};
    vector<int> ret {1,2,3,4,5,6};
    Solution soln;
    soln.merge(nums1, 1, nums2, 5);
    assert(isArrayEqual(ret, nums1));
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    cout << "Successful\n";
    return 0;
}
