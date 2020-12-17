#include "../include.h"

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return sum(root, low, high);
    }

    int sum(TreeNode *root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }
        int val = (root->val >= low && root->val <= high) ? root->val : 0;
        return val + sum(root->left, low, high) + sum(root->right, low, high);
    }
};

void test1() {
    TreeNode *tree = new TreeNode(10, new TreeNode(5, new TreeNode(3), new TreeNode(7)), \
            new TreeNode(15, nullptr, new TreeNode(18)));
    Solution soln;
    assert(soln.rangeSumBST(tree, 7 ,15) == 32);
}

void test2() {
    TreeNode *tree = new TreeNode(10, new TreeNode(5, \
        new TreeNode(3, new TreeNode(1), nullptr), \
        new TreeNode(7, new TreeNode(6), nullptr)), \
        new TreeNode(15, new TreeNode(13), new TreeNode(18)));
    Solution soln;
    assert(soln.rangeSumBST(tree, 6, 10) == 23);
}

int main() {
    test1();
    test2();
    cout << "Successful\n";
    return 0;
}
