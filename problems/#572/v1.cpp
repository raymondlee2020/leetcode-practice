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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) {
            return false;
        }
        bool ret = false;
        if (root->val == subRoot->val) {
            ret |= isSameTree(root, subRoot);
        }
        ret |= isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        return ret;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return p == NULL || q == NULL ? p == q : p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};