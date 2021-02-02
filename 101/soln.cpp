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
// Uncomment only one #define below
// #define RECURSIVE
#define ITERATIVE

#ifdef RECURSIVE
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }

    bool isMirror(TreeNode *l, TreeNode *r) {
        if (l == nullptr or r == nullptr) return l == r;
        return l->val == r->val and isMirror(l->left, r->right) and isMirror(l->right, r->left);
    }
};
#endif

#ifdef ITERATIVE
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;
        q1.push(root->left);
        q2.push(root->right);
        while (not q1.empty() and not q2.empty()) {
            TreeNode *front1 = q1.front();
            TreeNode *front2 = q2.front();
            q1.pop();
            q2.pop();
            if (front1 == nullptr and front2 == nullptr) continue;
            if ((front1 == nullptr and front2 != nullptr) or (front1 != nullptr and front2 == nullptr)) return false;
            if (front1->val != front2->val) return false;
            if ((q1.empty() and not q2.empty()) or (not q1.empty() and q2.empty())) return false;
            q1.push(front1->left);
            q1.push(front1->right);
            q2.push(front2->right);
            q2.push(front2->left);
        }
        return true;
    }
};
#endif

void test() {
    TreeNode *t1 = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    TreeNode *t2 = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(3)), new TreeNode(2, nullptr, new TreeNode(3)));
    Solution soln;
    assert(soln.isSymmetric(t1));
    assert(!soln.isSymmetric(t2));
}

int main() {
    test();
    cout << "Successful\n";
    return 0;
}
