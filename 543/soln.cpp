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
    int maxLen = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        int root_diameter = 0;
        if (root != nullptr) {
            root_diameter = getHeight(root->left) + getHeight(root->right);
        }
        return max(maxLen, root_diameter);
    }

    /* calculates height of root and updates max diameter */
    int getHeight(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int left_H = getHeight(root->left);
        int right_H = getHeight(root->right);
        maxLen = max(maxLen, right_H + left_H);
        return 1 + max(left_H, right_H);
    }
};

void test1() {
    TreeNode *tree = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), \
            new TreeNode(3));
    Solution soln;
    assert(soln.diameterOfBinaryTree(tree) == 3);
}

void test2() {
    TreeNode *tree = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    Solution soln;
    assert(soln.diameterOfBinaryTree(tree) == 2);
}

void test3() {
    TreeNode *tree = nullptr;
    Solution soln;
    assert(soln.diameterOfBinaryTree(tree) == 0);
}

int main() {
    test1();
    test2();
    test3();
    cout << "Successful\n";
    return 0;
}
