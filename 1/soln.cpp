#include "../include.h"

// uncomment only one of the methods to run
// #define BRUTE_FORCE
#define HASH_TABLE

#ifdef BRUTE_FORCE
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret(2, 0);
		for (int i = 0; i < nums.size() - 1; ++i) {
			for (int j = i + 1; j < nums.size(); ++j) {
				if (nums[i] + nums[j] == target) {
					ret[0] = i;
					ret[1] = j;
					return ret;
				}
			}
		}
		return ret;
    }
};
#endif

#ifdef HASH_TABLE
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_seen;
        vector<int> ret (2, 0);
        for (int i = 0; i < nums.size(); ++i) {
            auto itr = nums_seen.find(target - nums[i]);
            if (itr != nums_seen.end()) {
                ret[0] = itr->second;
                ret[1] = i;
            } else {
                nums_seen[nums[i]] = i;
            }
        }
        return ret;
    }
};
#endif

int main() {
	Solution soln;
	vector<int> v1{1,2,3}, ret1{0, 2};
	assert(is_permutation(ret1.begin(), ret1.end(), soln.twoSum(v1, 4).begin()));
	cout << "Successful" << endl;
}
