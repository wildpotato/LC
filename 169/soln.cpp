#include "../include.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash_table;
        for (int i = 0; i < nums.size(); ++i) {
            auto itr = hash_table.find(nums[i]);
            if (itr != hash_table.end()) {
                itr->second++;
            } else {
                hash_table.insert(make_pair(nums[i], 1));
            }
        }
        //printMap(hash_table);
        auto beg = hash_table.begin();
        int maxEle = beg->first;
        int maxOccur = beg->second;
        for (auto itr : hash_table) {
            if (itr.second > maxOccur) {
                maxEle = itr.first;
                maxOccur = itr.second;
            }
        }
        return maxEle;
    }
};

void test1() {
    vector<int> nums {3,2,3};
    Solution soln;
    assert(soln.majorityElement(nums) == 3);
}

void test2() {
    vector<int> nums {2,2,1,1,1,2,2};
    Solution soln;
    assert(soln.majorityElement(nums) == 2);
}

void test3() {
    vector<int> nums {6,5,5};
    Solution soln;
    assert(soln.majorityElement(nums) == 5);
}

int main() {
    test1();
    test2();
    test3();
    cout << "Successful\n";
    return 0;
}
