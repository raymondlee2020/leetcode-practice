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
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        bool ret = isBalanced(root->left) && isBalanced(root->right);
        if (!ret) {
            return ret;
        }
        int ldep = root->left == NULL ? 0 : root->left->val, rdep = root->right == NULL ? 0 : root->right->val;
        root->val = max(ldep, rdep) + 1;
        return ret && abs(ldep - rdep) <= 1;
    }
};