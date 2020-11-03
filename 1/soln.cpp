#include "../include.h"

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

int main() {
	Solution soln;
	vector<int> v1{1,2,3}, ret1{0, 2};
	assert(soln.twoSum(v1, 4) == ret1);
	cout << "Successful" << endl;
}
