#include "../include.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
		return buildTree(nums, 0, nums.size());
    }
	TreeNode* buildTree(vector<int> &nums, int lo, int hi) {
		if (lo >= hi)
			return nullptr;
		int mid = (lo + hi) / 2;
		TreeNode *root = new TreeNode(nums[mid]);
		root->left = buildTree(nums, lo, mid);
		root->right = buildTree(nums, mid + 1, hi);
		return root;
	}
};

void test() {
	vector<int> nums {-10,-3,0,5,9};
	Solution soln;
	assert(isBST(soln.sortedArrayToBST(nums)));
}

int main() {
	test();
	cout << "Successful\n";
	return 0;
}
