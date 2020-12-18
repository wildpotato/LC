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
    bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr) {
			return true;
		} else if (p == nullptr || q == nullptr) {
			return false;
		} else {
			return p->val == q->val && isSameTree(p->left, q->left) &&
				isSameTree(p->right, q->right);
		}
    }
};

void test1() {
	TreeNode *p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
	TreeNode *q = new TreeNode(1, new TreeNode(2), new TreeNode(3));
	Solution soln;
	assert(soln.isSameTree(p, q));
}

void test2() {
	TreeNode *p = new TreeNode(1, new TreeNode(2), nullptr);
	TreeNode *q = new TreeNode(1, nullptr, new TreeNode(2));
	Solution soln;
	assert(!soln.isSameTree(p, q));
}

int main() {
	test1();
	test2();
	cout << "Successful\n";
	return 0;
}
