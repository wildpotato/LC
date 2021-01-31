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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr) return false;
        return isIdentical(s, t) or isSubtree(s->right, t) or isSubtree(s->left, t);
    }

    bool isIdentical(TreeNode *s, TreeNode *t) {
        if (s == nullptr and t == nullptr) return true;
        if (s == nullptr or t == nullptr) return false;
        if (s->val != t->val) return false;
        return isIdentical(s->right, t->right) and isIdentical(s->left, t->left);
    }
};

void test1() {
    TreeNode *s = new TreeNode (3, new TreeNode (4, new TreeNode(1), new TreeNode(2)), new TreeNode(5));
    TreeNode *t = new TreeNode(4, new TreeNode(1), new TreeNode(2));
    Solution soln;
    assert(soln.isSubtree(s, t));
}

void test2() {
    TreeNode *s = new TreeNode (3, new TreeNode (4, new TreeNode(1), new TreeNode(2, new TreeNode(0), nullptr)), new TreeNode(5));
    TreeNode *t = new TreeNode(4, new TreeNode(1), new TreeNode(2));
    Solution soln;
    assert(!soln.isSubtree(s, t));
}

int main() {
    test1();
    test2();
    cout << "Successful\n";
    return 0;
}
