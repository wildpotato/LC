#include "../include.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		constexpr int MAX_NUM_DUPLICATES = 2;
		int n = nums.size();
		if (n <= MAX_NUM_DUPLICATES) {
			return n;
		}
		/* i is the slow ptr and j is the fast ptr */
		auto i = nums.begin();
		int count = 0, curr_num = *i;
		for (auto j = i; j != nums.end(); ++j) {
			if (*j == curr_num) { // duplicates
				if (count == MAX_NUM_DUPLICATES) {
					--i;
					nums.erase(j);
					j = i;
				} else {
					++count;
					++i;
				}
			} else { // encounter new number
				curr_num = *j;
				count = 1;
				++i;
			}
		} // for
		return nums.size();
	}
};

void test1() {
	vector<int> input {1,1,1,2,2,3};
	vector<int> golden {1,1,2,2,3};
	Solution soln;
	int len = soln.removeDuplicates(input);
	assert(isArrayEqual(input, golden, len));
}

void test2() {
	vector<int> input {0,0,1,1,1,1,2,3,3};
	vector<int> golden {0,0,1,1,2,3,3};
	Solution soln;
	int len = soln.removeDuplicates(input);
	printArray(input);
	cout << "len = " << len;
	assert(isArrayEqual(input, golden, len));
}

int main() {
	test1();
	test2();
	cout << "Successful\n";
	return 0;
}
