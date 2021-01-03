#include "../include.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		vector<int> left_prod(n, 1);
		vector<int> right_prod(n, 1);
		vector<int> ret(n);
		for (int i = 1; i < n; ++i) {
			left_prod[i] = left_prod[i-1] * nums[i-1];
		}
		for (int i = n - 2; i >= 0; --i) {
			right_prod[i] = right_prod[i+1] * nums[i+1];
		}
		for (int i = 0; i < n; ++i) {
			ret[i] = left_prod[i] * right_prod[i];
		}
		return ret;
    }
};

void test1() {
	Solution soln;
	vector<int> input {1,2,3,4};
	vector<int> output {24,12,8,6};
	vector<int> ret = soln.productExceptSelf(input);
	assert(isArrayEqual(ret, output));
}

int main() {
	test1();
	cout << "Successful\n";
	return 0;
}
